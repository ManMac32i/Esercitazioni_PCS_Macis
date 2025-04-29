# include "Utils.hpp"
# include "PolygonalMesh.hpp"
# include <fstream>
# include <iostream>
# include <sstream>
# include <vector>

using namespace std;


namespace PolygonalLibrary 
{
bool ImportMesh(PolygonalMesh& mesh)
{
    if (!importCell0Ds(mesh))
        return false;
    if (!importCell1Ds(mesh))
        return false;
    if (!importCell2Ds(mesh))
        return false;

    return true;
}

bool importCell0Ds(PolygonalMesh& mesh)
{
    ifstream file("./Cell0Ds.csv");

    if (!file)
        return false;

    list<string> listlines;
    string line;

    while(getline(file,line))
        listlines.push_back(line);
    
    file.close();

    listlines.pop_front();

    mesh.NumCell0 = listlines.size();

    if (mesh.NumCell0 == 0)
    {
        cout << "There is no Cell0" << endl;
        return false;
    }

    mesh.Cell0Id.reserve(mesh.NumCell0);
    mesh.Cell0coordinates = Eigen::MatrixXd::Zero(2, mesh.NumCell0);

    for (const string& line : listlines)
    {
        istringstream convertor(line);

        unsigned int id;
        unsigned int marker;
        char semcol;

        convertor >> id >> semcol >> marker >> semcol >> mesh.Cell0coordinates(0, id) >> semcol >> mesh.Cell0coordinates(1, id);
        mesh.Cell0Id.push_back(id);
        if(marker != 0)
		{
			const auto it = mesh.MarkerCell0.find(marker);
			if(it!=mesh.MarkerCell0.end())
			{
				it -> second.push_back(id);
			}
			else 
			{
				mesh.MarkerCell0.insert({marker,{id}});
			}
		}

    }
    return true;
}

bool importCell1Ds(PolygonalMesh& mesh)
{
    ifstream file("./Cell1Ds.csv");

    if (!file)
        return false;

    list<string> listlines;
    string line;

    while(getline(file,line))
        listlines.push_back(line);
    
    file.close();

    listlines.pop_front();

    mesh.NumCell1 = listlines.size();

    if (mesh.NumCell1 == 0)
    {
        cout << "There is no Cell1" << endl;
        return false;
    }

    mesh.Cell1Id.reserve(mesh.NumCell1);
    mesh.Cell1orgin_end = Eigen::MatrixXd::Zero(2, mesh.NumCell1);

    for (const string& line : listlines)
    {
        istringstream convertor(line);

        unsigned int id;
        unsigned int marker;
        char semcol;

        convertor >> id >> semcol >> marker >> semcol >> mesh.Cell1orgin_end(0, id) >> semcol >> mesh.Cell1orgin_end(1, id);
        mesh.Cell1Id.push_back(id);

        if(marker != 0)
		{
			const auto it = mesh.MarkerCell1.find(marker);
			if(it!=mesh.MarkerCell1.end())
			{
				it -> second.push_back(id);
			}
			else 
			{
				mesh.MarkerCell1.insert({marker,{id}});
			}
		}

        if (mesh.Cell1orgin_end(0, id) == mesh.Cell1orgin_end(1, id))
        {
            cout << "At least one edge has a zero-length" << endl;
            return false;
        }

    }
    return true;
}

bool importCell2Ds(PolygonalMesh& mesh)
{
    ifstream file("./Cell2Ds.csv");

    if (!file)
        return false;

    list<string> listlines;
    string line;

    while(getline(file,line))
        listlines.push_back(line);

    file.close();

    listlines.pop_front();

    mesh.NumCell2 = listlines.size();

    if (mesh.NumCell2 == 0)
    {
        cout << "There is no Cell2" << endl;
        return false;
    }

    mesh.Cell2Id.reserve(mesh.NumCell2);

    for (const string& line : listlines)
    {
        istringstream convertor(line);

        unsigned int id;
        unsigned int marker;
        unsigned int NumVertices;
        unsigned int NumEdges;
        char semcol;
        vector <unsigned int> vertices;
        vector <unsigned int> edges;

        convertor >> id >> semcol >> marker >> semcol >> NumVertices;
        for (unsigned int i = 0; i < NumVertices; i++)
        {
            unsigned int vertex;
            convertor >> semcol >> vertex;
            vertices.push_back(vertex);
        }

        convertor >> NumEdges;
        for (unsigned int j = 0; j < NumEdges; j++)
        {
            unsigned int edgex;
            convertor >> semcol >> edgex;
            edges.push_back(edgex);
        }

        mesh.Cell2Id.push_back(id);
        mesh.Cell2Vertices[id] = vertices;
        mesh.Cell2Edges[id] = edges;

        double area;
        for (unsigned int i = 0; i < NumVertices; i++)
        {
            unsigned int j = (i + 1) % NumVertices;
            const Eigen::MatrixXd coord = mesh.Cell0coordinates;
            double x1 = coord(0, vertices[i]);
            double y1 = coord(1, vertices[i]);
            double x2 = coord(0, vertices[j]);
            double y2 = coord(1, vertices[j]);
            area += (x1 * x2) - (y1 * y2);
        }
        area = abs(area) * 0.5;
        if (area < 1e-16)
        {
            cout << "There is at least a zero Polygon with area equal to zero" << endl;
        }

    }
    return true;
}


}
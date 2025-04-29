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
    mesh.Cell0coordinates = Eigen::MatrixXd::Zero(3, mesh.NumCell0);

    for (const string& line : listlines)
    {
        istringstream convertor(line);

        unsigned int id;
        unsigned int marker;

        convertor >> id >> marker >> mesh.Cell0coordinates(0, id) >> mesh.Cell0coordinates(1, id);
        mesh.Cell0Id.push_back(id);
        mesh.MarkerCell0[id] = marker;

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
    mesh.Cell1orgin_end = Eigen::MatrixXd::Zero(3, mesh.NumCell1);

    for (const string& line : listlines)
    {
        istringstream convertor(line);

        unsigned int id;
        unsigned int marker;

        convertor >> id >> marker >> mesh.Cell1orgin_end(0, id) >> mesh.Cell1orgin_end(1, id);
        mesh.Cell1Id.push_back(id);
        mesh.MarkerCell1[id] = marker;

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

    if (mesh.NumCell1 == 0)
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
        vector <unsigned int> vertices;
        vector <unsigned int> edges;

        convertor >> id >> marker >> NumVertices;
        for (unsigned int i = 0; i < NumVertices; i++)
        {
            convertor >> vertices[i];
        }

        convertor >> NumEdges;
        for (unsigned int j = 0; j < NumEdges; j++)
        {
            convertor >> edges[j];
        }

        mesh.Cell1Id.push_back(id);
        mesh.Cell2Vertices[id] = vertices;
        mesh.Cell2Edges[id] = edges;

    }
    return true;
}


}
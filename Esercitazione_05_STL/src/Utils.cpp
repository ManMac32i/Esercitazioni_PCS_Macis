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

    }
    return true;
}

bool importCell1Ds(PolygonalMesh& mesh)
{
    return true;
}

bool importCell2Ds(PolygonalMesh& mesh)
{
    return true;
}


}
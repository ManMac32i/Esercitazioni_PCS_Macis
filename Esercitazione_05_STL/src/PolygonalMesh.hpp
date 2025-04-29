# pragma once

#include <iostream>
#include <vector>
#include "Eigen/Eigen" 

using namespace std;

namespace PolygonalLibrary 
{
    struct PolygonalMesh
    {
        unsigned int NumCell0 = 0;
        vector <unsigned int> Cell0Id;
        Eigen::MatrixXd Cell0coordinates;
        map <unsigned int, list<unsigned int>> MarkerCell0;

        unsigned int NumCell1 = 0;
        vector <unsigned int> Cell1Id;
        Eigen::MatrixXi Cell1orgin_end;
        map <unsigned int, list<unsigned int>> MarkerCell1;

        unsigned int NumCell2 = 0;
        vector <unsigned int> Cell2Id;
        map <unsigned int, vector<unsigned int>> Cell2Vertices;
        map <unsigned int, vector<unsigned int>> Cell2Edges;
    };
}

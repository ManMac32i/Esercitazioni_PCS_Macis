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
        Eigen::Matrix2Xd Cell0coordinates;
        map <unsigned int, unsigned int> MarkerCell0;

        unsigned int NumCell1 = 0;
        vector <unsigned int> Cell1Id;
        Eigen::Matrix2Xd Cell0orgin_end;
        map <unsigned int, unsigned int> MarkerCell1;

        unsigned int NumCell2 = 0;
        vector <unsigned int> Cell1Id;
        Eigen::Matrix2Xd Cell0orgin_end;
        map <unsigned int, vector<unsigned int>> VerticesCell2;
        map <unsigned int, vector<unsigned int>> EdgesCell2;
    };
}

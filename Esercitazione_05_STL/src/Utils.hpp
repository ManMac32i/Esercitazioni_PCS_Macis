# pragma once 

# include <iostream>
# include "PolygonalMesh.hpp"

using namespace std;


namespace PolygonalLibrary 
{
bool ImportMesh(PolygonalMesh& mesh);

bool importCell0Ds(PolygonalMesh& mesh);

bool importCell1Ds(PolygonalMesh& mesh);

bool importCell2Ds(PolygonalMesh& mesh);

}
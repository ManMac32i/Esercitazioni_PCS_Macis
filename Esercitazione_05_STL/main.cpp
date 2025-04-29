# include <iostream>
# include "Utils.hpp"
# include "PolygonalMesh.hpp"

using namespace std;
using namespace PolygonalLibrary;

int main()
{
    PolygonalMesh mesh;

    if (!ImportMesh(mesh))
    {
        cout << "Mesh correctly imported" << endl;
    }

    return 0;
}

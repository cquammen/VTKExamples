[VTKExamples](/home/)/[Cxx](/Cxx)/PolyData/TriangleArea

**TriangleArea.cxx**
```c++
#include <vtkSmartPointer.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkTriangle.h>

int main(int, char *[])
{
  //setup points (geometry)
  vtkSmartPointer<vtkPoints> points =
    vtkSmartPointer<vtkPoints>::New();
  points->InsertNextPoint ( 0.0, 0.0, 0.0 );
  points->InsertNextPoint ( 1.0, 0.0, 0.0 );
  points->InsertNextPoint ( 1.0, 1.0, 0.0 );
  points->InsertNextPoint ( 0.0, 1.0, 0.0 );

  //create a triangle on the three points in the polydata
  vtkSmartPointer<vtkTriangle> triangle1 =
    vtkSmartPointer<vtkTriangle>::New();
  triangle1->GetPointIds()->SetId ( 0, 0 );
  triangle1->GetPointIds()->SetId ( 1, 1 );
  triangle1->GetPointIds()->SetId ( 2, 2 );

  vtkSmartPointer<vtkTriangle> triangle2 =
    vtkSmartPointer<vtkTriangle>::New();
  triangle2->GetPointIds()->SetId ( 0, 2 );
  triangle2->GetPointIds()->SetId ( 1, 3 );
  triangle2->GetPointIds()->SetId ( 2, 0 );

  //add the triangles to the list of triangles
  vtkSmartPointer<vtkCellArray> triangles =
    vtkSmartPointer<vtkCellArray>::New();
  triangles->InsertNextCell ( triangle1 );
  triangles->InsertNextCell ( triangle2 );

  //create a polydata object
  vtkSmartPointer<vtkPolyData> polydata =
    vtkSmartPointer<vtkPolyData>::New();

  //add the geometry and topology to the polydata
  polydata->SetPoints ( points );
  polydata->SetPolys ( triangles );

  for(vtkIdType i = 0; i < polydata->GetNumberOfCells(); i++)
  {
    vtkCell* cell = polydata->GetCell(0);

    vtkTriangle* triangle = dynamic_cast<vtkTriangle*>(cell);
    double p0[3];
    double p1[3];
    double p2[3];
    triangle->GetPoints()->GetPoint(0, p0);
    std::cout << "p0: " << p0[0] << " " << p0[1] << " " << p0[2] << std::endl;
    triangle->GetPoints()->GetPoint(1, p1);
    std::cout << "p1: " << p1[0] << " " << p1[1] << " " << p1[2] << std::endl;
    triangle->GetPoints()->GetPoint(2, p2);
    std::cout << "p2: " << p2[0] << " " << p2[1] << " " << p2[2] << std::endl;

    double area = vtkTriangle::TriangleArea(p0, p1, p2);

    std::cout << "area of triangle " << i << ": " << area << std::endl;
  }
  return EXIT_SUCCESS;
}
```
**CMakeLists.txt**
```cmake
cmake_minimum_required(VERSION 2.8)
 
PROJECT(TriangleArea)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(TriangleArea MACOSX_BUNDLE TriangleArea.cxx)
 
target_link_libraries(TriangleArea ${VTK_LIBRARIES})
```

**Download and Build TriangleArea**

Click [here to download TriangleArea](https://github.com/lorensen/VTKWikiExamplesTarballs/raw/master/TriangleArea.tar) and its *CMakeLists.txt* file.
Once the *tarball TriangleArea.tar* has been downloaded and extracted,
```
cd TriangleArea/build 
```
If VTK is installed:
```
cmake ..
```
If VTK is not installed but compiled on your system, you will need to specify the path to your VTK build:
```
cmake -DVTK_DIR:PATH=/home/me/vtk_build ..
```
Build the project:
```
make
```
and run it:
```
./TriangleArea
```
**WINDOWS USERS PLEASE NOTE:** Be sure to add the VTK bin directory to your path. This will resolve the VTK dll's at run time.

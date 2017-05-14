#include <vtkSmartPointer.h>
#include <vtkFloatArray.h>

int main(int, char *[])
{
  vtkSmartPointer<vtkFloatArray> distances =
    vtkSmartPointer<vtkFloatArray>::New();
  distances->SetName("Distances");
  distances->SetNumberOfComponents(3);
  distances->SetNumberOfTuples(5);

  //set values
  for(vtkIdType i = 0; i < distances->GetNumberOfTuples(); i++)
  {
    float tuple[3];
    tuple[0] = (float)i + 0.1;
    tuple[1] = (float)i + 0.2;
    tuple[2] = (float)i + 0.3;
    distances->SetTuple(i, tuple);
  }

  //get values
  for(vtkIdType i = 0; i < distances->GetNumberOfTuples(); i++)
  {
    double d[3];
    distances->GetTuple(i, d);
    std::cout << d[0] << " " << d[1] << " " << d[2] << std::endl;
  }

  return EXIT_SUCCESS;
}
#include <iostream>
using namespace std;

class Simulation
{
public:
  Simulation(string filename);
  ~Simulation();

  int size;
  int* bubbleArray;
  int* insertionArray;
  int* quicksortArray;
  int* shellArray;

  void bubbleSort();
  void insertionSort();
  void runQuickSort();
  void quickSort(int* myArray, int left, int right);
  void shellSort();
};
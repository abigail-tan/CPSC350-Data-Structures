#include "Simulation.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;

Simulation::Simulation(string filename)
{
  //open file;
  ifstream f(filename.c_str());
  if (f)
  {
        string line;
    int lineNum = 1;
    int n;

    //read the file and put the info into the arrays
    while (getline(f,line))
    {
      //converts the read number from a string to an int
        stringstream toInt(line);
        toInt >> n;
        if (lineNum == 1)
        {
        size = n;
        bubbleArray = new int[size];
        insertionArray = new int[size];
        quicksortArray = new int[size];
        shellArray = new int[size];
        ++lineNum;
        }
        else
        {
        bubbleArray[lineNum-2] = n;
        insertionArray[lineNum-2] = n;
        quicksortArray[lineNum-2] = n;
        shellArray[lineNum-2] = n;
        ++lineNum;
            if(lineNum-1 == size)
            {
                break;
            }
        }
    }
  }
  else
  {
        cout << "File not found." << endl;
  }
  f.close();
}

Simulation::~Simulation()
{
  delete[] bubbleArray;
  delete[] insertionArray;
  delete[] quicksortArray;
  delete[] shellArray;
}


void Simulation::bubbleSort()
{
  int* arr = bubbleArray;
  cout << "Bubble Sort" << endl;
  cout << "Start time: " << (double)clock()/(double)CLOCKS_PER_SEC << endl;
    for(int i = 0; i < size-1; ++i) 
    {
        int temp = 0;
        for (int j = 0; j < size - 1 - i; ++j) 
        {
            if(arr[j] > arr[j+1]) 
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
  cout << "End time: " << (double)clock()/(double)CLOCKS_PER_SEC << endl;
}

void Simulation::insertionSort()
{
  int* arr = insertionArray;
  cout << "Insertion Sort" << endl;
  cout << "Start time: " << (double)clock()/(double)CLOCKS_PER_SEC << endl;
    for(int j = 1; j < size; ++j)
    {
        double temp = arr[j];
        int k = j;

        while (k>0 && arr[k-1] >= temp)
        {
            arr[k] = arr[k-1];
            --k;
        }
        arr[k] = temp;
    }
  cout << "End time: " << (double)clock()/(double)CLOCKS_PER_SEC << endl;
}

void Simulation::quickSort(int* myArray, int left, int right)
{
      int i = left;
      int j = right;
      int temp;
      int pivot = myArray[(left + right) / 2];

      while (i <= j)
      {
            while (myArray[i] < pivot)
            {
              i++;
            }
            while (myArray[j] > pivot)
            {
              j--;
            }
            if (i <= j)
            {
                  temp = myArray[i];
                  myArray[i] = myArray[j];
                  myArray[j] = temp;
                  i++;
                  j--;
            }
      };

      if (left < j)
      {
        quickSort(myArray, left, j);
      }
      if (i < right)
      {
        quickSort(myArray, i, right);
      }
}

void Simulation::runQuickSort() {
  cout << "QuickSort" << endl;
  cout << "Start time: " << (double)clock()/(double)CLOCKS_PER_SEC << endl;
  quickSort(quicksortArray,0,size);
  cout << "End time: " << (double)clock()/(double)CLOCKS_PER_SEC << endl;
}

void Simulation::shellSort()
{
    int* arr = shellArray;
    cout << "Shell Sort" << endl;
    cout << "Start time: " << (double)clock()/(double)CLOCKS_PER_SEC << endl;
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = arr[i];
 
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    cout << "End time: " << (double)clock()/(double)CLOCKS_PER_SEC << endl;
}

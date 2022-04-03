#include <ctime>
#include <iomanip>
#include <iostream>
#include "Assignment7.h"
using namespace std;

//Setting the random array
void randomArraySet(int arr[], int num)
{
      for (int i = 0; i < num; i++) {
      int n = rand() % num;
      arr[i] = n;
    }
}

//Selection Sort

//Insertion Sort

//Bubble Sort

//Merge Sort

//Quick Sort


// heapSort
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to reset the array
void resetArray(int arrOne[], int arrTwo[], int num)
{
  for(int i=0;i<num;i++)
    {
      arrOne[i] = arrTwo[i];
    }
}

//Menu function with case statements
int menu(int option, int arr[], int arrTwo[], int num){

    switch (option) {
    case 1:
      cout << "Selection Sort" << endl;
      selectionSort(arr, num);
      printArray(arr, 50);
      resetArray(arr, arrTwo, num);
      break;
    case 2:
      cout << "Insertion Sort" << endl;
      insertionSort(arr, num);
      printArray(arr, 50);
      resetArray(arr, arrTwo, num);
      break;
    case 3:
      cout << "Bubble Sort" << endl;
      bubbleSort(arr, num);
      printArray(arr, 50);
      resetArray(arr, arrTwo, num);
      break;
    case 4:
      cout << "Merge Sort" << endl;
      mergeSort(arr, 0, num-1);
      printArray(arr, 50);
      resetArray(arr, arrTwo, num);
      break;
    case 5:
      cout << "Quick Sort" << endl;
      quickSort(arr, 0, num - 1);
      printArray(arr, 50);
      resetArray(arr, arrTwo, num);
      break;
    case 6:
      cout << "Heap Sort" << endl;
      heapSort(arr, num);
      printArray(arr, 50);
      resetArray(arr, arrTwo, num);
      break;
          case 7:
      cout << "Original Array" << endl;
      printArray(arr, 50);
      resetArray(arr, arrTwo, num);
      break;
    case 0:
      exit(0);
      break;
    default:
      cout << "Wrong option! Try again." << endl;
      break;
  } 
  return option;
}

//Function to print menu
void printMenu() {
  cout << setw(17) << "MENU" << endl;
  cout << setw(17) << "1. Selection Sort" << endl;
  cout << "2. Insertion Sort" << endl;
  cout << "3. Bubble Sort" << endl;
  cout << "4. Merge Sort" << endl;
  cout << "5. Quick Sort" << endl;
  cout << "6. Heap Sort" << endl;
  cout << "7. Original Array" << endl;
  cout << "0. Quit" << endl;
}

//Function to copy array
void copyArray(int arrOne[], int arrTwo[], int num) {
  for (int i = 0; i < num; i++) {
    arrTwo[i] = arrOne[i];
  }
}

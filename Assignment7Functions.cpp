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

//Swap function
void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

//Selection Sort
void selectionSort(int arr[], int n) {
  int outer, inner, min;
  for (outer = 0; outer < n - 1; outer++) {
    min = outer;

    for (inner = outer + 1; inner < n; inner++) {
      if (arr[inner] < arr[min]) {
        min = inner;
      }
    }
    int temp = arr[outer];
    arr[outer] = arr[min];
    arr[min] = temp;
  }

}

//Insertion Sort
void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
  for (int i = 0; i < 50; i++) {
    cout << arr[i] << " ";
  }
}

//Bubble Sort
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
      }
    }
  }
  for (int i = 0; i < 50; i++) {
    cout << arr[i] << " ";
  }
}

//Merge Sort
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  /* create temp arrays */
  int L[n1], R[n2];
  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];
  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  /* Copy the remaining elements of L[], if there
     are any */
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  /* Copy the remaining elements of R[], if there
     are any */
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Same as (l+r)/2, but avoids overflow for
    // large l and h
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}
//Quick Sort
void quickSort(int arr[], int left, int right) {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];

  /* partition */
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }
  };
  /* recursion */
  if (left < j)
    quickSort(arr, left, j);
  if (i < right)
    quickSort(arr, i, right);
}

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

//Print Array Function(Prints first 50 of the array)
void printArray(int A[], int size) {
  int i;
  for (i = 0; i < size-1; i++)
    cout << A[i] << "->";
  cout << A[size];
  cout << endl;
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

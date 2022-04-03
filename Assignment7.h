#ifndef Assignment7_H
#define Assignment7_H


void printMenu();
int menu(int answer, int arr[], int arrTwo[], int num);
void copyArray(int arrOne[], int arrTwo[], int num);
void printArray(int A[], int size);
void randomArraySet(int arr[], int num);
void swap(int arr[], int i, int j);
void resetArray(int arrOne[], int arrTwo[], int num);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int left, int right);


#endif 

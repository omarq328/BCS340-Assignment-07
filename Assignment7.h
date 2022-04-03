#ifndef Assignment7_H
#define Assignment7_H


void printMenu();
int menu(int answer, int arr[], int arrTwo[], int num);
void copyArray(int arrOne[], int arrTwo[], int num);
void randomArraySet(int arr[], int num);
void resetArray(int arrOne[], int arrTwo[], int num);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void selectionSort(int arr[], int n);
void quickSort(int arr[], int left, int right);


#endif 

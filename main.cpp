#include <ctime>
#include <iomanip>
#include <iostream>
#include "Assignment7.h"
using namespace std;



int main() {
int choice, choiceTwo;
    clock_t start, end;
    
    int num = 10000;
    int low = 0;
    int high = num - 1;

    int arr[num];
    randomArraySet(arr, num);

    int copyArr[num];
    copyArray(arr, copyArr, num);
do {
  start = clock();
  system("clear");
    cout << "============================" << endl;
    printMenu();
    cout << "============================" << endl;
    cout << "Please select an option: ";
    cin >> choice;
system("clear");
    menu(choice, arr, copyArr, num);
      end = clock();
    double time_taken = 1000 * double(end - start) / double(CLOCKS_PER_SEC);
    cout << endl
         << "Time taken by program is : " << fixed << time_taken
         << setprecision(5);
    cout << " ms " << endl;
  cout << "Enter 0 to exit or any number to go back to menu! " << endl;
  cin >> choiceTwo;
  if (choiceTwo == 0)
    return 0;

  }while (choice != 0);

  
}

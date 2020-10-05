/**************************
 *Derek Walker
 *CPSC 1021, 003, F20
 *djwalke@g.clemson.edu
 *Elliot McMillan
 *This program allows the user to build an array of employeess, randomizes
  the order of the array, create a smaller array, and then organizes the 
  employees in alphabetical order by last name, and displays their information 
 **************************/
//This is to test the -m flag
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct Employee{
  string lastName;
  string firstName;
  int birthYear;
  double hourlyWage;
}employee;

bool name_order(const employee& lhs, const employee& rhs);
int myrandom (int i) {return rand()%i;}

int main(int argc, char const *argv[]){
  //Generates a random seed each time the program is run
  srand(unsigned (time(0)));
  int (*funp)(int){&myrandom}; 
  employee roster[10];
  employee* p = roster;
  for(int i = 0; i < 10; i++){
    cout << "Enter last name of employee " << (i+1) << ": ";
    cin >> roster[i].lastName;
    cout << "Enter first name of employee " << (i+1) << ": ";
    cin >> roster[i].firstName;
    cout << "Enter birth year of employee " << (i+1) << ": ";
    cin >> roster[i].birthYear;
    cout << "Enter hourly wage of employee " << (i+1) << ": ";
    cin >> roster[i].hourlyWage;
    cout << endl;
  }
  
  //Shuffles the entire array of employees
  random_shuffle(p,(p + 10), funp);

  employee sorted[5] = {roster[0],roster[1],roster[2],roster[3],roster[4]};
  employee* sp = sorted;
  //Sorts the smaller array by last name
  sort(sp, (sp + 5), name_order);

  for(employee i:sorted){
    cout << fixed << setw(50) << right << i.lastName + ", " +  i.firstName;
    cout << endl << fixed  << setw(50) << right << i.birthYear << endl;
    //Line over 80 characters, used style shown in Formatting & Styles example
    cout << fixed << setw(50) << right << showpoint<< setprecision(2) 
         << i.hourlyWage << endl;
  }

  return 0;
}
/*
 *name_order allows the program to compare the last names of adjacent structs
 *Parameter 1: constant employee reference type to struct on left
 *Parameter 2: constant employee reference type to struct on right
 *Return: Boolean that is true if the right hand side is larger and false
  otherwise. Essentially tells sort if the location in the array needs swapped
*/
bool name_order(const employee& lhs, const employee& rhs){
  if(lhs.lastName < rhs.lastName){
    return true;
  }
  else{
    return false;
  }
}


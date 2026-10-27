#include <iostream>
#include "recordtools.h"

using namespace std;

// Global variables to store one record
string studentName;
double score;

void addRecord()
{
    cout << "Enter student name: ";
    cin >> studentName;

    cout << "Enter score: ";
    cin >> score;
}

void displayRecord()
{
    cout << "\nStudent Record" << endl;
    cout << "Name: " << studentName << endl;
    cout << "Score: " << score << endl;
}

double calculateResult()
{
    return score;
}
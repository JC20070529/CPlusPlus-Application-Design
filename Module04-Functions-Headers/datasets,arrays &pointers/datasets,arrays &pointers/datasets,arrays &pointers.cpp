/*
Assignment: Kaggle Dataset Arrays and Pointers
Dataset Source:
Kaggle Titanic Dataset
https://www.kaggle.com/code/chanchal24/titanic-dataset
Selected Fields:
Name
Age
Fare
Selected Records:
Braund
Cumings
Heikkinen
Futrelle
Allen
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string names[5];
    int ages[5];
    double fares[5];

    ifstream file("titanic.csv");

    if (!file)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    string header;
    getline(file, header); // Skip header row

    char comma;

    for (int i = 0; i < 5; i++)
    {
        getline(file, names[i], ',');
        file >> ages[i];
        file >> comma;
        file >> fares[i];

        file.ignore(1000, '\n');
    }

    file.close();

    cout << "Titanic Dataset Records" << endl;
    cout << "-----------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << names[i]
             << ", Age: " << ages[i]
             << ", Fare: $" << fares[i]
             << endl;
    }

    double* farePtr = &fares[0];

    cout << endl;
    cout << "First fare through pointer: "
         << *farePtr
         << endl;

    return 0;
}

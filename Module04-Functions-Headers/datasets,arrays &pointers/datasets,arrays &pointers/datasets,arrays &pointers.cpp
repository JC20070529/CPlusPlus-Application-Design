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
using namespace std;
int main()
	{
string names[5] ={
		"Braund",
		"Cumings",
	    "Heikkinen",
		"Futrelle",
		"Allen"
		};
int ages[5] =
		{
		22,
		38,
		26,
		35,
		35
		};
double fares[5] =
		{
		7.25,
		71.2833,
		7.925,
		53.10,
		8.05
		};

double* farePtr = &fares[0];

			cout << "Titanic Dataset Records" << endl;
			for (int i = 0; i < 5; i++)
			{
			cout << names[i]<< ", Age: " << ages[i]<< ", Fare: $" << fares[i]<< endl;
			}
			cout << endl;
			cout << "First fare through pointer: "<< *farePtr << endl;
			return 0;
}

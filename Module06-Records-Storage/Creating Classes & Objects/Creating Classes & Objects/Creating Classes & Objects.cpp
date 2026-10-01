#include <iostream>
using namespace std;
class Student {
private:
	string name;
	int age;
	double gpa;
public:
	Student(string n, int a, double g) {
		name = n;
		age = a;
		gpa = g;
	}
	void study(){
		cout << name << " is studying." << endl;
	}
	void displayinfo() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "GPA: " << gpa << endl;
	}
	string getName() {
		return name;
	}
	double getGPA(double g) {
		gpa = g;
	}

};
int main(){
	Student s1("Josephine", 20, 3.5);
	s1.study();
	s1.displayinfo();
	Student s2("Jian", 19, 3.8);
	s2.study();
	s2.displayinfo();
	return 0;
}



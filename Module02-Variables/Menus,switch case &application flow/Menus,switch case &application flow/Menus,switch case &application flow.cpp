#include <iostream>
#include <string>
using namespace std;

void addStudent(){
	cout << "Add Student selected" << endl;
}
void viewStudent() {
	cout << "View Student selected" << endl;
}
void searchStudent() {
	cout << "Search Student selected" << endl;
}
void updateStudent() {
	cout << "Update Student selected" << endl;
}
void deleteStudent() {
	cout << "Delete Student selected" << endl;
}
int main()
{
	int choice = 0;
	while (choice != 6) {
		cout << "\n===Student Management System===" << endl;
		cout << "1. Add Student" << endl;
		cout << "2. View Student" << endl;
		cout << "3. Search Student" << endl;
		cout << "4. Update Student" << endl;
		cout << "5. Delete Student" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			addStudent();
			break;
		case 2:
			viewStudent();
			break;
		case 3:
			searchStudent();
			break;
		case 4:
			updateStudent();
			break;
		case 5:
			deleteStudent();
			break;
		case 6:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	system("pause>0");
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
public:
    int id;
    string name;
    double score;
};

class GradeTracker
{
private:
    Student students[100];
    int count;

public:
    GradeTracker()
    {
        count = 0;
    }

    void addStudent()
    {
        if (count >= 100)
        {
            cout << "Array is full!" << endl;
            return;
        }

        while (true)
        {
            cout << "Enter Student ID: ";

            if (cin >> students[count].id &&
                students[count].id > 0)
            {
                break;
            }

            cout << "Invalid ID. Please enter a positive number." << endl;

            cin.clear();
            cin.ignore(10000, '\n');
        }

        while (true)
        {
            cout << "Enter Student Name: ";
            cin >> students[count].name;

            if (!students[count].name.empty())
            {
                break;
            }

            cout << "Name cannot be empty." << endl;
        }

        while (true)
        {
            cout << "Enter Student Score (0-100): ";

            if (cin >> students[count].score &&
                students[count].score >= 0 &&
                students[count].score <= 100)
            {
                break;
            }

            cout << "Invalid score. Enter a value between 0 and 100." << endl;

            cin.clear();
            cin.ignore(10000, '\n');
        }

        count++;
         sortStudents();
            cout << "Student added successfully!" << endl;
        }

    void displayStudents()
    {
        if (count == 0)
        {
            cout << "No students found." << endl;
            return;
        }

        cout << "\nStudent List\n";
        cout << "------------------------" << endl;

        for (int i = 0; i < count; i++)
        {
            Student* ptr = &students[i];

            cout << "ID: " << ptr->id
                << " Name: " << ptr->name
                << " Score: " << ptr->score
                << endl;
        }
    }

    void sortStudents()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (students[i].id > students[j].id)
                {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    void searchStudent()
    {
        if (count == 0)
        {
            cout << "No students available." << endl;
            return;
        }

        int target;

        cout << "Enter ID to search: ";
        cin >> target;

        int left = 0;
        int right = count - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (students[mid].id == target)
            {
                cout << "\nStudent Found!" << endl;
                cout << "ID: " << students[mid].id << endl;
                cout << "Name: " << students[mid].name << endl;
                cout << "Score: " << students[mid].score << endl;
                return;
            }

            if (students[mid].id < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << "Student not found." << endl;
    }

    void saveToFile()
    {
        ofstream file("students.txt");

        if (!file)
        {
            cout << "Error opening file." << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            file << students[i].id << " "
                << students[i].name << " "
                << students[i].score << endl;
        }

        file.close();

        cout << "Data saved successfully." << endl;
    }

    void loadFromFile()
    {
        ifstream file("students.txt");

        if (!file)
        {
            cout << "No file found." << endl;
            return;
        }

        count = 0;

        while (file >> students[count].id
            >> students[count].name
            >> students[count].score)
        {
            count++;
        }

        file.close();

        cout << "Data loaded successfully." << endl;
    }
};

int main()
{
    cout << "Data Type Sizes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "bool: " << sizeof(bool) << " bytes" << endl;

    GradeTracker tracker;

    int choice;

    do
    {
        cout << "\n===== Student Grade Tracker =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Save to File" << endl;
        cout << "5. Load from File" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 6)
        {
            cout << "Invalid choice. Please enter 1-6: ";

            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (choice)
        {
        case 1:
            tracker.addStudent();
            break;

        case 2:
            tracker.displayStudents();
            break;

        case 3:
            tracker.searchStudent();
            break;

        case 4:
            tracker.saveToFile();
            break;

        case 5:
            tracker.loadFromFile();
            break;

        case 6:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}
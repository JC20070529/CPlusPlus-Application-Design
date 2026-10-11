#include <iostream>
using namespace std;
class Record {
public:
int id;
string name;

};
class User {
protected:
	string username;

public:
	User(string name):username(name){}
};
class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void addRecord() {
        cout << "Record Added" << endl;
    }

    void deleteRecord() {
        cout << "Record Deleted" << endl;
    }
};
class RegularUser : public User {
public:
    RegularUser(string name) : User(name) {}

    void viewRecord() {
        cout << "Viewing Records" << endl;
    }
};
int binarySearch(int data[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (data[mid] == target)
            return mid;

        if (data[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
int main()
{
    Admin admin("Tom");
    RegularUser user("Jack");

    admin.addRecord();
    admin.deleteRecord();

    user.viewRecord();

    int ids[] = { 1200,1201,1202,1203,1204 };

    int result = binarySearch(ids, 5, 1203);

    cout << "Found at index: " << result << endl;

    return 0;
}

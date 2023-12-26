#include<iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    int salary;

public:
    Employee() {}

    Employee(int _id, string _name, int _salary) {
        id = _id;
        name = _name;
        salary = _salary;
    }

    void setID(int _id) {
        id = _id;
    }

    void setName(string _name) {
        name = _name;
    }

    int getID() {
        return id;
    }

    string getName()  {
        return name;
    }
    void setSalary(int _salary) {
        salary= _salary;
    }

    int getSalary()  {
        return salary;
    }

};

int linearSearchByID( Employee emp[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (emp[i].getID() == key)
            return i;
    }
    return -1;
}
int linearSearchBySalary( Employee emp[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (emp[i].getSalary()== key)
            return i;
    }
    return -1;
}

int linearSearchByName( Employee emp[], int n, string key) {
    for (int i = 0; i < n; i++) {
        if (emp[i].getName()== key)
            return i;
    }
    return -1;
}
int main() {
    const int numEmployees = 5;
    Employee employees[numEmployees] = {
        {101, "John", 100},
        {103, "Alice", 500},
        {102, "Bob", 600},
        {105, "Eve", 50},
        {104, "Charlie", 60}
    };

    int num;
    cout << "Enter an Integer: ";
    cin >> num;
    string name;
    cout << "Enter an name: ";
    cin >> name;

    int result = linearSearchByID(employees, numEmployees, num);
    if (result == -1)
        cout << "The Number: (" << num << ") Was Not Found." << endl;
    else
        cout << "The Number: (" << employees[result].getID() << ") Was Found At Index: (" << result << ")" << endl;
    result = linearSearchByName(employees, numEmployees, name);
    if (result == -1)
        cout << "The Number: (" << num << ") Was Not Found." << endl;
    else
        cout << "The Number: (" << employees[result].getID() << ") Was Found At Index: (" << result << ")" << endl;

    return 0;
}

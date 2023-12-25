#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

using namespace std;

class Employee {
private:
    int id;
    string name;

public:
    Employee() {}

    Employee(int _id, string _name) {
        id = _id;
        name = _name;
    }

    void setID(int _id) {
        id = _id;
    }

    void setName(string _name) {
        name = _name;
    }

    int getID() const {
        return id;
    }

    string getName() const {
        return name;
    }
};


void bubbleSort(Employee arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
           if (arr[j].getID() > arr[j + 1].getID()) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void Ascending(int &i,int &x){
     if (i > x) {
        swap(i,x);
    }
}
void descending(int &i,int &x){
     if (i < x) {
        swap(i,x);
    }
}
void printArray(const Employee arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "ID: " << arr[i].getID() << ", Name: " << arr[i].getName() << endl;
    }
}

int main() {
    const int numEmployees = 5;


    Employee employees[numEmployees] = {
        {101, "John"},
        {103, "Alice"},
        {102, "Bob"},
        {105, "Eve"},
        {104, "Charlie"}
    };


    cout << "Original array of Employees:\n";
    printArray(employees, numEmployees);


    bubbleSort(employees, numEmployees);


    cout << "\nSorted array of Employees by ID:\n";
    printArray(employees, numEmployees);

    return 0;
}

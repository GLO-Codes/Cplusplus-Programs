#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int rate = 11;

struct Employee {
    string name;
    string address;
    string employeeNo;
    double hours;
    double total;
    double tax;
    double net;
};

vector<Employee> readRecordsFromFile(const string& filename) {
    vector<Employee> employees;
    ifstream file(filename.c_str());
    string line;

    while (getline(file, line)) {
        Employee emp;
        emp.name = line;
        getline(file, emp.address);
        getline(file, emp.employeeNo);
        file >> emp.total;
        file >> emp.tax;
        file >> emp.net;
        file.ignore(); 
        employees.push_back(emp);
    }

    file.close();
    return employees;
}

void writeRecordsToFile(const string& filename, const vector<Employee>& employees) {
    ofstream file(filename.c_str());
    for (size_t i = 0; i < employees.size(); ++i) {
        file << employees[i].name << endl;
        file << employees[i].address << endl;
        file << employees[i].employeeNo << endl;
        file << employees[i].total << endl;
        file << employees[i].tax << endl;
        file << employees[i].net << endl;
    }

    file.close();
}

int main() {
    string filename = "output.txt";
    vector<Employee> employees = readRecordsFromFile(filename);
    
    for (size_t i = 0; i < employees.size(); ++i) {
        Employee& currentRecord = employees[i];
        cout << "Record No. " << (i + 1) << ":\n";
        cout << "Name: " << currentRecord.name << endl;
        cout << "Address: " << currentRecord.address << endl;
        cout << "Employee No.: " << currentRecord.employeeNo << endl;
        cout << "Total: " << currentRecord.total << endl;
        cout << "Tax: " << currentRecord.tax << endl;
        cout << "Net: " << currentRecord.net << endl;
        cout << endl;

        cout << "Do you want to edit this record? (yes/no): ";
        string editChoice;
        cin >> editChoice;
        
        if (editChoice == "yes") {
            cin.ignore(); 
            cout << "Enter the new data for the record:" << endl;
            cout << "Name: ";
            getline(cin, currentRecord.name);
            cout << "Address: ";
            getline(cin, currentRecord.address);
            cout << "Employee No.: ";
            getline(cin, currentRecord.employeeNo);
            cout << "No. of hours worked: ";
            cin >> currentRecord.hours;
            currentRecord.total = currentRecord.hours * rate;
            currentRecord.tax = currentRecord.total * 0.1;
            currentRecord.net = currentRecord.total - currentRecord.tax;

            writeRecordsToFile(filename, employees);
            cout << "Record updated successfully!" << endl;
        }
        cout << endl;
    }

    return 0;
}


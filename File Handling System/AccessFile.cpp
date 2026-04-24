#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream inputFile("output.txt");
	if (!inputFile.is_open())
	{
		cerr << "Unable to open the file for reading. " << endl;
		return 1;
	}
	string line;
	int linesDisplayed = 0;
	int recordCount = 0;
	int index = 0;
	string n[9];
	n[0] = "Name :";
	n[1] = "Grade :";
	n[2] = "Student ID. :";
	n[3] = "Math Grade :";
	n[4] = "Science Grade :";
	n[5] = "English Grade :";
	n[6] = "History Grade :";
	n[7] = "P.E. Grade :";
	n[8] = "Average Grade :";

	cout << "\n\t\t\t\tStudent Record" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;

	while (getline(inputFile, line))
	{
		if (linesDisplayed == 0)
		{
			recordCount++;
			cout << "Record No. " << recordCount <<  endl;
		}
		cout << "\t" << n[index++] << line  << endl;
		linesDisplayed++;

		if (linesDisplayed == 3)
		{
			cout << "-------------------------------------------------------------------------------------------" << endl;
			cout << "\t\t\t       *Subject Grades*" << endl;
		}

		if (linesDisplayed == 8){

			cout << endl;
		}

		if (linesDisplayed == 9)
		{
			cout << "-------------------------------------------------------------------------------------------" << endl;
			cout << endl;
			cout << "Press enter to view next record. ";
			cin.get();
			system("cls");
			cout << "\n\t\t\tSubject Grades" << endl;
			cout << "-----------------------------------------------------------------------------------------" << endl;
			linesDisplayed = 0;
			index = 0;
		}
	}

	inputFile.close();
	return 0;

}


//Another Method of Accesing file using Struct and display funtion
/*

struct Student{
string name;
string grade
string sid;
double math;
double science
double english;
double history;
double pe;
double average;
}

void displaystudent(){



}




*/
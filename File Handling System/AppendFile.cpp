#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

	int record;

	string name[10], grade[10];
	double studentid[10], average[10], math[10], science[10], english[10], history[10], pe[10];

	cout << "How Many Records Do You Want To Add? (Max 10) ";
	cin >> record;

	for (int i = 0; i < record; i++)
	{
		cout << endl;
		cout << "Name: ";
		cin >> name[i];
		cout << "Grade: ";
		cin >> grade[i];
		cout << "Student ID: ";
		cin >> studentid[i];
		cout << "Math Grade: ";
		cin >> math[i];
		cout << "Science Grade: ";
		cin >> science[i];
		cout << "English Grade: ";
		cin >> english[i];
		cout << "History Grade: ";
		cin >> history[i];
		cout << "P.E Grade: ";
		cin >> pe[i];

		average[i] = (math[i] + science[i] + english[i] + history[i] + pe[i]) / 5;
	}


	ofstream outputFile("output.txt", ios::app);
	if (outputFile.is_open()){
		for(int i = 0; i < record; i++){
			outputFile << name[i] << endl;
			outputFile << grade[i] << endl;	
			outputFile << studentid[i] << endl;
			outputFile << math[i] << endl;	
			outputFile << english[i] << endl;
			outputFile << history[i] << endl;
			outputFile << science[i] << endl;	
			outputFile << pe[i] << endl;	
			outputFile << average[i] << endl;	
		}
			outputFile.close();
		cout << endl;
		cout <<"Data has been appended to file." << endl;
		
	} else{
		cerr <<"Unable to open the file for appending" << endl;
		return 1;
	}
return 0;	



}
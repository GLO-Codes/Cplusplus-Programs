#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
	const int rate = 11;
	int rec;
	char ent;
	string name[10],add[10],emp[10];
	double hours[10], pay[10],total[10],net[10],tax[10],gross[10];
	
	cout << "How many records do you want to enter?: ";
	cin >> rec;
	
	for(int i = 0; i < rec; i++){
		cout << endl;
		cout << "Enter name: ";
		cin >> name[i];
		cout << "Enter address: ";
		cin >> add[i];
		cout << "Enter Employee no. ";
		cin >> emp[i];
		cout << "No. of hours worked: ";
		cin >> hours[i];
		total[i] = hours[i] * rate;
		tax[i] = total[i] * 0.1;
		net[i] = total[i] - tax [i];
	}
	
	ofstream outputFile("output.txt");
	if (outputFile.is_open()){
		for(int i = 0; i < rec; i++){
			outputFile << name[i] << endl;
			outputFile << add[i] << endl;	
			outputFile << emp[i] << endl;
			outputFile << total[i] << endl;	
			outputFile << tax[i] << endl;
			outputFile << net[i] << endl;	
				
		}
		outputFile.close();
		cout << endl;
		cout <<"Data has been written to file." << endl;
		
	} else{
		cerr <<"Unable to open the file for writing" << endl;
		return 1;
	}
	
	
	
	
	return 0;
}

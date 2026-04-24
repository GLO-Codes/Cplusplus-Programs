#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	
		int index = 0;
	string n[7]; 
		n[0] = "Name :"; 
		 n[1] = "Address :"; 
		 n[2] = "Employee No. :"; 
		n[3] = "Total :"; 
		 n[4] = "tax :"; 
		 n[5] = "Net :"; 
		 
		 
    string input_file_path = "output.txt";
    string output_file_path = "outputnew.txt";

    //ifstream input_file(input_file_path); 
	ifstream input_file(input_file_path.c_str());


    if (!input_file.is_open()) {
        cerr << "Failed to open the input file." << endl;
        return 1; 
    }

   
  //  ofstream output_file(output_file_path); 
    ofstream output_file(output_file_path.c_str());


    if (!output_file.is_open()) {
        cerr << "Failed to create/open the output file." << endl;
        input_file.close();
        return 1; 
    }

    vector<string> current_record;
    string line;
    int line_count = 0;
    const int lines_per_record = 6;
    bool delete_record = false;

    while (getline(input_file, line)) {
       
        current_record.push_back(line);

        
        line_count++;

        
        if (line_count % lines_per_record == 0) {
           
          for (size_t i = 0; i < current_record.size(); ++i) {
    cout << n[index++] << current_record[i] << endl;
}


           
            cout << "Do you want to delete this record? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice == 'Y' || choice == 'y') {
                delete_record = true;
                cout << "Record Deleted." << endl;
            }
cout << endl;
           
            if (!delete_record) {
               for (size_t i = 0; i < current_record.size(); ++i) {
    output_file << current_record[i] << endl;
}

            }

            
            current_record.clear();

           
            delete_record = false;
        }
        index = 0;
    }

    
    input_file.close();
    output_file.close();

    
    if (remove(input_file_path.c_str()) != 0) {
        cerr << "Error deleting the original file." << endl;
        return 1; 
    }
    
    if (rename(output_file_path.c_str(), input_file_path.c_str()) != 0) {
        cerr << "Error renaming the output file." << endl;
        return 1; 
    }

    cout << "End of file reached." << endl;

    return 0; 
}

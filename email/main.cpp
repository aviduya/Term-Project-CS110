//
//  main.cpp
//  email
//
//  Created by Anfernee Viduya on 5/10/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string emailDetector(string line) {
    int symbolLocation = 0;
    string handle;
    string address;
    
    for (int i = 0; i <= line.length(); i++) {
        if (line[i] != '@') {
            symbolLocation++;
        } else {
            break;
        }
    }
    
    for (int j = symbolLocation; line[j] != ' '; j--) {
        handle += line[j];
    }
    
    for (int k = symbolLocation + 1; line[k] != ' '; k++) {
        address += line[k];
    }
    
    reverse(handle.begin(), handle.end());
    
    return handle + address;
}

int main() {
    
    string emailArray[2];
    
    // MARK: Create Variables for Files & Ask for the file location and name
    
    string inputFileName = "testEmail.txt";
    string outputFileName;
    
//    cout << "Enter the name of the file: ";
//    getline(cin, inputFileName);
    
    fstream inputF(inputFileName);
    
    
    // MARK: Check if the File location is valid, if not, re-run program
    
    if (!inputF.good()) {
        cerr << "Could not find the file." << endl;
        main();
    }
    
    // MARK: Read the file contents
    
    string line;
    
    while (getline(inputF, line)) {
        
        if (line.find('@') == string::npos) {
            continue;
        }
        
        cout << emailDetector(line) << endl;

        
    }
   
}


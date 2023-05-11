//
//  main.cpp
//  email
//
//  Created by Anfernee Viduya on 5/10/23.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void testInput(string test) {
    cout << "Test Input: " <<test << endl;
}

int main() {
    
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
        
        string scannedLine;
        
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                scannedLine += line[i];
            } else {
                testInput(scannedLine);
                cout << "Found a space! Ending for now" << endl;
                return 0;
            }
        }
        
    }
}


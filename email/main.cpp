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
        int symbolLocation = 0;
        string emailHandle;
        
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != '@') {
                scannedLine += line[i];
                symbolLocation++;
            } else {
                break;
            }
        }
        
        for (int j = symbolLocation; scannedLine[j] != ' '; j--) {
            emailHandle += scannedLine[j];
        }
        
        reverse(emailHandle.begin(), emailHandle.end());
         
        cout << "This is scanned line: " << scannedLine << endl;
        cout << "Symbol Location: " << symbolLocation << endl;
        cout << "Email Handle: " << emailHandle << "@dvc.edu" << endl;
        
    }
}


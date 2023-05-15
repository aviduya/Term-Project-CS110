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
#include "email_functions.h"
using namespace std;

int main() {
    
    string inputFileName = "testEmail.txt";
    string outputFileName;
    
    fstream inputF(inputFileName);
    
    if (!inputF.good()) {
        cerr << "Could not find the file." << endl;
        main();
    }
    
    string line;
    string emailArray[1000];
    int indexOfArray = 0;
    
    while (getline(inputF, line)) {
    
        
        if (line.find('@') == string::npos) {
            continue;
        }
        
        string email = emailEngine(line);
        emailArray[indexOfArray] = email;
        indexOfArray++;
        
    }
    
    writeToFile("testOutputEmail", emailArray, indexOfArray);
   
}


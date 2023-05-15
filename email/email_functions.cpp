//
//  email_functions.cpp
//  email
//
//  Created by Anfernee Viduya on 5/15/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "email_functions.h"
using namespace std;

void writeToFile(string fileName, string emails[1000], int size) {
    ofstream file(fileName);
    
    for (int i = 0; i < size; i++) {
        file << emails[i] << "\n";
    }
 
    file.close();
    
}

string emailEngine(string line) {
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

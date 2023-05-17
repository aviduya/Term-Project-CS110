#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include "email_functions.h"
using namespace std;

int main() {
    
    string inputFileName = "testEmail.txt";
    string outputFileName;
    
    fstream inputF(inputFileName);
    
    if (!inputF.good()) {
        cerr << "Could not find the file " << "[" << inputFileName << "]" << endl;
        return 1;
    }
    
    string line;
    set<string> emailSet;
    
    while (getline(inputF, line)) {
    
        
        if (line.find('@') == string::npos) {
            continue;
        }
        
        string email = emailEngine(line);
        emailSet.insert(email);
        
    }
    
    writeToFile("testOutputEmail", emailSet);
   
}

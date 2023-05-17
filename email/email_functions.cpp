#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void writeToFile(string fileName, const set<string>& emails) {
    ofstream file(fileName);
    
    for (const auto& email : emails) {
        file << email << "; ";
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

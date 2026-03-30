#pragma once
#ifndef MY_FILE_HEADER
#define MY_FILE_HEADER

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ENTRY_SIZE = 500;  // Each file entry block: 500 bytes
const int MAX_FILES = 2097; // 1MB / 500B = 2097 entries

class HeaderFiles {
private:
    map<string, int> fileMap; // filename â†’ address

public:
    void initialize() {
        fileMap.clear();
        cout << "FileTable initialized.\n";
    }


    bool addFile(string fileName, int address) {


        fileMap[fileName] = address;

        return true;
    }

    bool deleteFile(string& fileName) {
        fileMap.erase(fileName);
        return true;
    }

    void display() const {
        cout << "\nFile Table Contents:\n";
        cout << left << setw(30) << "File Name" << "\t" << "Start Address\n";
        for (const auto& entry : fileMap) {
            cout << left << setw(30) << entry.first << "\t" << entry.second << endl;
        }
    }

    bool checkName(const string& name)const {

        return fileMap.count(name);

    }

    int getAdress(const string& nameOfFile)const {

        return fileMap.at(nameOfFile);
    }


    map<string, int>& getmap() {
       return fileMap;
    }

};
#endif

// saveToDisk removed ;
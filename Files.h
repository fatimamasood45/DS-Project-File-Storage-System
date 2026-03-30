#pragma once
#ifndef PART_3
#define PART_3
#include <iostream>
#include <vector>
#include <deque>
#include <map>

// TASK
/*
Third portion (8MB) of your file â€œFile_systemâ€ should be reserved for the data
 to be written in the files listed in first portion of your â€œFile_systemâ€.
*/
using namespace std;

const int MAX_FILE_SIZE = 1023;
const int MAX_BLOCK_COUNT = 16776;
class Block {
public:
    int address;
    string data;


    Block(int addr, string d = "") : address(addr), data(d) {}


    Block() {
        address = 0;
        data = " ";
    }

};

class Files {
private:
    map<int, deque<Block>> files;

public:

    Block& getLastBlock(int fileAdress) {

        return files.at(fileAdress)[files.at(fileAdress).size() - 1];

    }

    bool appendToFile(int fileAddress, Block block) {

        files.at(fileAddress).push_back(block);
        return true;

    }

    bool createNewFile(Block parent) {

        deque<Block> parentBlock;

        parentBlock.push_back(parent);
        files.insert({ parent.address , parentBlock });
        return true;

    }

    bool removeFromEnd(int address) {

        if (!files.count(address)) return false;

        if (files.at(address).size() == 1) {
            if (deleteFile(address)) return true;
            return false;
        }

        files.at(address).erase(files.at(address).end() - 1);
        return true;

    }

    bool deleteFile(int address) {

        files.erase(address);
        return true;

    }

    deque<int> getAddresses(int address) {

        deque<int> toReturn;

        for (auto& data : files.at(address))  toReturn.push_back(data.address);

        return toReturn;
    }

    deque<Block> getFile(int address) {

        return files.at(address);

    }

    void display(int address) {

        deque<Block>& blocks = files.at(address);
        for (auto& block : blocks) {
            cout << block.data << endl;
        }

    }

};

#endif
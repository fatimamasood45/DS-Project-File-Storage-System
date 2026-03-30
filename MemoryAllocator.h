#pragma once
#ifndef MEMORYALLOCATER
#define MEMORYALLOCATER
// FreeBlockManager.hpp
#include <iostream>
#include <map>
#include <vector>
#include <queue> 

using namespace std;


const int BLOCK_SIZE = 1024;     //1KB block size
const int DATA_START = 2 * 1024 * 1024; //2MB (start of 8MB data portion)
// 1024*1024 /4  totalnumber of bytes / 4 = number of addresses we can hold 

class MemoryAllocator {
public:

    map<int, bool> AllocatedMemory;  //Key: block address (int),     Value: free status (bool)
    priority_queue<int, vector<int>, greater<int>> FreeMemory;
    // 1 int is 4 bytes , 2 
        // Checks if address is valid (aligned to 1KB and within 8MB)



public:
    MemoryAllocator() {

        initializeMemory();

    }

    void initializeMemory() {
        for (int addr = DATA_START; addr < DATA_START + 8 * 1024 * 1024; addr += BLOCK_SIZE) {
            FreeMemory.push(addr);   //addr:2MB to 10MB
        }
    }

    // Allocate the first available free block(first fit strategy)
    bool allocateBlock(int& allocatedAddress) {
        if (FreeMemory.empty()) return false; //validation

        allocatedAddress = FreeMemory.top();
        AllocatedMemory.insert({ FreeMemory.top() , 0 });
        FreeMemory.pop();
        return true;

    }

    // Mark a block as free
    bool deallocateBlock(int address) {

        FreeMemory.push(address);
        AllocatedMemory.erase(address);
        return true;

    }

    vector<int> getFreeBlocksList() {
        vector<int> blocks;
        for (const auto& pair : AllocatedMemory) {
            if (pair.second) { // If block is free
                blocks.push_back(pair.first);
            }
        }
        return blocks;
    }



    bool isAvailable() {

        return FreeMemory.size();

    }


};


#endif 
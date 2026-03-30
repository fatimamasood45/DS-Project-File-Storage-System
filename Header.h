#ifndef MANAGER
#define MANAGER 
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN


#include "FileHeaders.h" 
#include "Files.h"
#include "MemoryAllocator.h"
#include <string>
#include <filesystem>
#include <Windows.h>


using namespace std;
namespace fs = std::filesystem;

const string NAMEOFFILE = "FileNames.txt";
const string FILEPATH = fs::current_path().string();

class FileSystemManager {

    HeaderFiles headerfiles;
    Files files;
    MemoryAllocator memoryAllocator;

    int headerfileSize;
    int fileCount = 0;
    int blockCount = 0;
public:
    // working
    bool addFile(string nameOfFile) {

        if (nameOfFile.size() + 5 > ENTRY_SIZE) return false;
        if (headerfiles.checkName(nameOfFile)) return false;
        if (!memoryAllocator.isAvailable()) return false;
        if (fileCount > MAX_FILES)  return false;
        if (!(blockCount < MAX_BLOCK_COUNT)) return false;

        int address;

        memoryAllocator.allocateBlock(address);
        headerfiles.addFile(nameOfFile, address);

        Block block(address);
        files.createNewFile(block);

        fileCount++;
        blockCount++;

        return true;
    }

    // List all files (returns map: filename → file size)
    map<string, int> listFiles() {
        map<string, int> fileList;
        map<string, int>& headerMap = headerfiles.getmap();

        for (map<string, int>::iterator it = headerMap.begin(); it != headerMap.end(); it++) {
            string name = it->first;
            int address = it->second;
            deque<Block> blocks = files.getFile(address);

            int totalSize = 0;
            for (deque<Block>::iterator blockIt = blocks.begin(); blockIt != blocks.end(); ++blockIt) {
                totalSize += blockIt->data.size();
            }
            fileList[name] = totalSize;
        }
        return fileList;
    }

    // View file content (returns content as string)
    string viewFile(const string& fileName) {
        if (!headerfiles.checkName(fileName)) return "Error: File not found.";

        int address = headerfiles.getAdress(fileName);
        deque<Block> blocks = files.getFile(address);

        string content;
        for (deque<Block>::iterator it = blocks.begin(); it != blocks.end(); ++it) {
            content += it->data;
        }
        return content;
    }

    // working 
    bool deleteFile(string nameOfFile) {

        if (!headerfiles.checkName(nameOfFile)) return false;

        int address = headerfiles.getAdress(nameOfFile);

        deque<int> addresses = files.getAddresses(address);

        for (auto& address : addresses) {

            memoryAllocator.deallocateBlock(address);
            blockCount--;

        }

        files.deleteFile(address);
        headerfiles.deleteFile(nameOfFile);
        fileCount--;
        string filename = (fs::current_path() / (nameOfFile + ".txt")).string();
        fs::remove(filename);
        return true;

    }
    // working
    bool copyFileFromWindows(string name, string path = FILEPATH) {
        string input;
        string data = "";
        if (!addFile(name)) return false;
        ifstream file(path + "/" + name + ".txt");

        if (!file.is_open()) return false;

        while (getline(file, input)) {
            data += input + "\n";
        }

        file.close();

        if (!Modify(name, data)) return false;

        return true;
    }
    // working
    bool copyFileToWindows(string nameOfFile, const string windowsPath = FILEPATH) {

        if (!headerfiles.checkName(nameOfFile)) {
            cerr << "Error: File '" << nameOfFile << "' not found.\n";
            return false;
        }

        int address = headerfiles.getAdress(nameOfFile);
        deque<Block> fileBlocks = files.getFile(address);

        ofstream outFile(windowsPath + '/' + nameOfFile + ".txt");
        if (!outFile) {
            cerr << "Error: Could not create output file.\n";
            return false;
        }

        for (const Block& block : fileBlocks) {
            outFile << block.data;  //write all block data
        }

        outFile.close();
        return true;
    }

    // working
    bool Modify(string nameOfFile, string data) {
        if (!headerfiles.checkName(nameOfFile))  return false;

        int headerAddress = headerfiles.getAdress(nameOfFile);
        Block& lastBlock = files.getLastBlock(headerAddress);

        int diff = 0;

        if (lastBlock.data.size() < MAX_FILE_SIZE) {

            diff = (data.size() > MAX_FILE_SIZE - lastBlock.data.size()) ? MAX_FILE_SIZE - lastBlock.data.size() : data.size();
            lastBlock.data += data.substr(0, diff + 1);

        }

        int subStart = diff;
        while (subStart < data.size()) {

            if (blockCount >= MAX_BLOCK_COUNT) return false;
            if (!memoryAllocator.isAvailable()) return false;

            Block block;
            memoryAllocator.allocateBlock(block.address);

            if (data.size() - subStart < MAX_FILE_SIZE) {
                block.data = data.substr(subStart, data.size() - subStart + 1);
                blockCount++;

                files.appendToFile(headerAddress, block);

                return true;
            }

            block.data = data.substr(subStart, MAX_FILE_SIZE);
            subStart = subStart + MAX_FILE_SIZE;
            files.appendToFile(headerAddress, block);
            blockCount++;

        }

        return true;
    }

    // working
    void Defragmentation() {

        map<string, int>& headermap = headerfiles.getmap();
        recursiveFragmentation(headermap.begin(), headermap.end());



    }

    // In FileSystemManager class declaration:
    int getFileAddress(const string& filename) const {
        return headerfiles.getAdress(filename);
    }

    HeaderFiles& getHeaderFiles() { return headerfiles; }
    MemoryAllocator& getMemoryAllocator() { return memoryAllocator; }
    Files& getFiles() { return files; }


    //working 
    ~FileSystemManager() {

        
             ofstream out(NAMEOFFILE);

            if (!out) {

                cerr << "Error: Could not create FileNames.txt\n";
                return;

            }

            map<string, int> headermap = headerfiles.getmap();

            for (const auto& [name, address] : headermap) {

                // Save file name to FileNames.txt
                out << name << '\n';
                string fileName = name;
                // Save file content to a separate file

                if (!copyFileToWindows(fileName, FILEPATH)) {
                    cerr << "Warning: Failed to save data for file " << name << '\n';
                }
            }

            out.close();

    }
    // working
    FileSystemManager() {
        ifstream in("FileNames.txt");

        if (in.is_open()) {

            string fileName;
            while (getline(in, fileName)) {
                copyFileFromWindows(fileName, FILEPATH);
            }
            in.close();

        }
        else
            cout << "No existing file FileNames.txt to load.\n";

    }

private:
    // working
    void recursiveFragmentation(map<string, int>::iterator it, map<string, int> ::iterator end) {
        if (it == end) return;

        deque<Block> file = files.getFile(it->second);

        files.deleteFile(it->second);


        for (auto& AddressToFree : file) {

            memoryAllocator.deallocateBlock(AddressToFree.address);

        }

        recursiveFragmentation(next(it), end);

        for (auto& AddresstoAllocate : file) {

            memoryAllocator.allocateBlock(AddresstoAllocate.address);

        }

        if (file.empty()) return;
        it->second = file[0].address;
        files.createNewFile(file[0]);

        for (int i = 1; i < file.size(); i++) {
            files.appendToFile(it->second, file[i]);
        }
    }

};
#undef byte


#endif
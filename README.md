📁 File Storage System (Virtual Disk Simulation)
📌 Overview

This project implements a Virtual File Storage System in C++, simulating a real-world file system inside a 10MB virtual disk file. It demonstrates core Object-Oriented Programming (OOP) concepts along with data structures to manage files efficiently.

The system supports essential file operations such as create, read, modify, delete, and copy, along with an advanced defragmentation feature to optimize storage.

🎯 Objectives
Simulate a 10MB virtual disk
Design a scalable OOP-based architecture
Manage:
Metadata (1MB)
Free space (1MB)
Data storage (8MB)
Implement file operations:
Create
Read / View
Modify
Delete
Copy (to/from Windows)
Handle dynamic memory allocation
Optimize storage using defragmentation
Ensure data persistence using RAM caching
🧠 System Design

The system is divided into three main sections:

Section	Size	Purpose
Metadata	1MB	Stores file names and starting addresses
Free Space	1MB	Tracks available memory blocks
Data Storage	8MB	Stores actual file data
🏗️ Core Classes
1. HeaderFiles
Manages file metadata
Stores filename and starting address using a map
Functions:
addFile()
deleteFile()
checkName()
getAddress()
display()
2. Files
Manages file content
Uses deque of blocks
Block contains:
Address
Data
Functions:
createNewFile()
appendToFile()
removeFromEnd()
deleteFile()
getFile()
3. MemoryAllocator
Handles memory allocation/deallocation
Uses:
map → allocated blocks
priority_queue → free blocks
Functions:
allocateBlock()
deallocateBlock()
isAvailable()
4. FileSystemManager
Main controller of the system
Combines all components
Functions:
addFile()
listFiles()
viewFile()
deleteFile()
Modify()
copyFileFromWindows()
copyFileToWindows()
Defragmentation()
⚙️ Features

✅ Virtual 10MB disk simulation
✅ File operations (Create, Read, Modify, Delete)
✅ Copy files between system and Windows
✅ Block-based storage (1024 bytes per block)
✅ Metadata management
✅ RAM-based processing (faster execution)
✅ Defragmentation support (bonus feature)
✅ Works with .txt files

🖥️ How It Works
At startup:
Virtual disk is loaded into RAM
During execution:
All operations are performed in memory
At termination:
Data is saved back to disk
📊 Sample Functionalities
📄 Create new file
📋 List all files
👁️ View file content
✏️ Modify file
❌ Delete file
🔄 Copy from/to Windows
🧹 Defragment storage
⚠️ Challenges & Solutions
🔹 Large Files Handling

Problem: Files larger than one block
Solution: Linked blocks (each block points to next)

🔹 Memory Management

Problem: Efficient allocation
Solution: Priority queue for free blocks

🔹 Data Integrity

Problem: Data corruption risk
Solution: Use delimiters and careful block tracking

🔹 Defragmentation

Problem: Fragmented storage
Solution: Recursive block rearrangement

🚀 Future Improvements
📂 Add directory & folder structure
📦 Support binary file formats
⚡ Implement caching for faster access
🗜️ Add file compression
🔧 Improve defragmentation algorithm
🛠️ Technologies Used
Language: C++
Concepts:
Object-Oriented Programming (OOP)
Data Structures (Map, Deque, Priority Queue)
File Handling

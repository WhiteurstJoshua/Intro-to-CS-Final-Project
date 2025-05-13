# Intro-to-CS-Final-Project

## Overview
This project is a modified version of an earlier file sorter I developed during my DPI Apprenticeship for web development. Originally written in Ruby, the file sorter automatically moved files from the Downloads folder in File Explorer to specific locations based on file type. In this version, the project is rewritten in C++ to enhance performance and to incorporate additional functionalities like file encryption and logging.

## Features
- **File Handling:** Read and write files efficiently in C++.
- **Encryption:** Encrypt and decrypt file content using a simple XOR-based algorithm.
- **Logging:** Maintain detailed logs of file operations with timestamps.
- **Modular Design:** Separate modules for Logger, Encryption, and File Management.

## Project Structure


## Module Descriptions

### Header Files
These files contain the declarations of functions, classes, constants, and macros. They provide the interface for the modules and allow other parts of the project to reference the functionalities without needing to know the underlying implementation details.

### Source Files
These files contain the actual definitions (implementations) of the functions and classes declared in the header files. Separating the implementation allows for better code organization and easier maintenance.

## Installation & Build Instructions
1. Open your terminal and navigate to the project directory.
2. Compile the project using the following command:
   ```bash
   g++ src/main.cpp src/FileManager.cpp src/Encryption.cpp src/Logger.cpp -o final_project

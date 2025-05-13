#include <iostream>
#include "Logger.h"
#include "FileManager.h"

int main() {
    Logger logger("file_log.txt");
    FileManager fm(logger);

    std::string filename = "example.txt";
    std::string data = "Hello, this is a sample data to be encrypted!";
    std::string key = "secretkey";

    // Write file with encryption enabled.
    if (fm.writeFile(filename, data, true, key))
        std::cout << "File written with encryption." << std::endl;
    else
        std::cout << "Failed to write file." << std::endl;

    // Read file with decryption enabled.
    std::string fileData;
    if (fm.readFile(filename, fileData, true, key))
        std::cout << "File read with decryption: " << fileData << std::endl;
    else
        std::cout << "Failed to read file." << std::endl;

    return 0;
}

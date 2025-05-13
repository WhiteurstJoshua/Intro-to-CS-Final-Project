#include "FileManager.h"
#include "Encryption.h"
#include <fstream>

FileManager::FileManager(FileManager &logger) : logger(logger) {}

bool FileManager::writeFile(const std::string &filename, const std::string &data, bool encrypt, const std::string &key) {
    std::string outputData = data;
    if (encrypt) {
        outputData = xorEncryptDecrypt(data, key);
        logger.log("Data encrypted before writing to file: " + filename);
    }
    
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        logger.log("Failed to open file for writing: " + filename);
        return false;
    }
    
    outFile << outputData;
    outFile.close();
    logger.log("Data successfully written to file: " + filename);
    return true;
}

bool FileManager::readFile(const std::string &filename, std::string &data, bool decrypt, const std::string &key) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        logger.log("Failed to open file for reading: " + filename);
        return false;
    }
    
    // Read entire file contents into a string.
    std::string fileContents((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();
    
    if (decrypt) {
        fileContents = xorEncryptDecrypt(fileContents, key);
        logger.log("Data decrypted after reading from file: " + filename);
    }
    
    data = fileContents;
    logger.log("Data successfully read from file: " + filename);
    return true;
}

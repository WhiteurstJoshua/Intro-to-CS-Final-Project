#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "FileManager.h"

class FileManager {
public:
    FileManager(FileManager &logger);
    bool writeFile(const std::string &filename, const std::string &data, bool encrypt = false, const std::string &key = "");
    bool readFile(const std::string &filename, std::string &data, bool decrypt = false, const std::string &key = "");
private:
    FileManager &logger;
};

#endif

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "Logger.h"

class FileManager {
public:
    FileManager(Logger &logger);
    bool writeFile(const std::string &filename, const std::string &data, bool encrypt = false, const std::string &key = "");
    bool readFile(const std::string &filename, std::string &data, bool decrypt = false, const std::string &key = "");
private:
    Logger &logger;
};

#endif



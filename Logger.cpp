#include "Logger.h"
#include <iomanip>

Logger::Logger(const std::string &filename) {
    // Open the file in append mode
    logFile.open(filename, std::ios::app);

}
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const std::string &message) {
    if (logFile.is_open()) {
        // Get the current time
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        auto now_tm = *std::localtime(&now_c);

        // Format the time
        logFile << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " - " << message << std::endl;
    }
}
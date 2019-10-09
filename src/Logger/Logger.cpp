#include <iostream>
#include "Logger.hpp"

using namespace std;

// Set the name for our logging
const string Logger::name = "ollylang";

/**
 * Log a message from the intepreter
 */
void Logger::log (const char *message, Logger::LogType logType) {
    switch (logType) {
        case Logger::Message:  
            cout << "\e[1;37m[" << name << "] " << message << "\033[0m" << endl;
            break;
        case Logger::Warning:
            cout << "\e[1;33m[" << name << "][WARN] " << message << "\033[0m" << endl;
            break;
        case Logger::Error: 
            cout << "\e[0;31m[" << name << "][ERR] " << message << "\033[0m"  << endl;
            break;
    }
}

/** 
 * Overload for logging a string
 */
void Logger::log (string message, Logger::LogType logType) {
    log(message.c_str(), logType);
}

/**
 * Overload for logging a char
 */
void Logger::log (char message, Logger::LogType logType) {

}
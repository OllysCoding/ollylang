#include <iostream>

using namespace std;

/**
 * This class is responsible for all the logging which comes from the ollylang interpreter
 **/
class Logger {

   public:
      /**
       * Name of our program, is the prefix of any log
       */
      const static string name;

      /**
       * Log type dictates the formatting of the log and allows us to make it clear to the end user what we are trying to tell them
       */
      enum LogType { Message, Warning, Error };

      /**
       * Log a message from the intepreter
       */
      static void log (const char *message, LogType logType = Message);

      /**
       * Overload for logging a string
       */
      static void log (string message, LogType logType = Message);

      /**
       * Overload for logging a character
       */
      static void log (const char message, LogType logType = Message);

};
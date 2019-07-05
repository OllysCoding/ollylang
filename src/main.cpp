#include <iostream>
#include <fstream>
#include "logger.hpp"

using namespace std;

/**
 * This class is responsible for any reading or writing of files which our interpreter requires
 **/
class FileHandler {
   public:
      /**
       * Reads in a file
       **/
      static string readFile (char* filename) {
         ifstream inFile;
         inFile >> ws;

         string result = "";
         string readIn = "";

         inFile.open(filename);
         if (!inFile) {
            throw "File does not exist";
         }

         while (getline(inFile, readIn)) {
            result += readIn + '\n'; 
         }

         inFile.close();

         return result;
      }
};

/**
 * Input stream is our own 'steam' implementation for our parser
 **/ 
class InputStream {
   int pos;
   int line;
   int col;
   string input;

   public:
      /**
       * Create an instance of our InputStream and initialise our variables
       **/
      InputStream(string inputStream) : pos(0), line(1), col(0), input(inputStream) {};
      
      /**
       * Returns the current character and moves us on to the next one
       **/
      char next() {
         // Access our character
         char ch = input.at(pos++);

         // If new line; reset col
         if (ch == '\n') {
            line++;
            col = 0;
         } else col++;

         // Return character
         return ch;
      }
      
      /**
       * Peeks at the current character that we're at  
       **/
      char peek() {
         return input.at(pos);
      }
      
      /**
       * Returns true if we are at the end of the file
       **/
      bool eof() {
         if (pos >= input.length()) {
            return true;
         } else {
            return false;
         }
      }
      
      /**
       * Throw an error for the current line and col
       **/
      void croak(string msg) {
         throw (msg + " (" + to_string(line) + ":" + to_string(col) + ")");
      }
};

enum TokenType { Punctuation, Numbrt, String, Keyword, Variable, Operator };

struct token {
   TokenType type;
   string value;
};

class TokenStream {

};

// main() is where program execution begins.
int main(int argc, char** argv) {
   try {
      if (argc != 2) {
         throw "Usage: ollylang <filename>";
      }

      char* filename = argv[1];

      string fileString = FileHandler::readFile(filename);

      InputStream* stream = new InputStream(fileString);

      Logger::log("this is a message");

      return 0;
   } catch (const char* ex) {
      cout << ex;
      return 0;
   } catch (const string ex) {
      cout << ex;
      return 0;
   }
}
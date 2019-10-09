#include <iostream>
#include <fstream>
#include "Logger/Logger.hpp"
#include "FileHandler/FileHandler.hpp"
#include "InputStream/InputStream.hpp"
#include "TokenStream/TokenStream.hpp"

using namespace std;

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
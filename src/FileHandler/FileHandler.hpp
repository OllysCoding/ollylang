#include <iostream>
#include <fstream>

using namespace std;

/**
 * This class is responsible for any reading or writing of files which our interpreter requires
 **/
class FileHandler {
   public:
      /**
       * Reads in a file
       **/
      static string readFile (char* filename);
};
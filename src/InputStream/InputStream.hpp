#include <iostream>

using namespace std;

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
      char next();

      /**
       * Peeks at the current character that we're at  
       **/
      char peek();
      
      /**
       * Returns true if we are at the end of the file
       **/
      bool eof();
      
      /**
       * Throw an error for the current line and col
       **/
      void croak(string msg);
};
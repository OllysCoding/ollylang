#include <iostream>
#include <fstream>
#include "InputStream.hpp"

using namespace std;

/**
 * Returns the current character and moves us on to the next one
 **/
char InputStream::next() {
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
char InputStream::peek() {
    return input.at(pos);
}

/**
 * Returns true if we are at the end of the file
 **/
bool InputStream::eof()  {
    if (pos >= input.length()) {
    return true;
    } else {
    return false;
    }
}

/**
 * Throw an error for the current line and col
 **/
void InputStream::croak(string msg) {
    throw (msg + " (" + to_string(line) + ":" + to_string(col) + ")");
}

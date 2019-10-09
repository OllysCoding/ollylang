#include <iostream>
#include <fstream>
#include "FileHandler.hpp"

using namespace std;

string FileHandler::readFile (char* filename) {
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
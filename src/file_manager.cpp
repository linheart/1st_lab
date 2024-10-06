#include "../include/file_manager.h"
#include <cassert>
#include <ostream>
#include <sstream>

void readValuesFromFile(const string &path, Data &data) {
  ifstream file(path);
  string line;
  int currentLine = 0;

  assert(file.is_open());

  while (getline(file, line)) {
    currentLine++;
    istringstream iss(line);
    string name;

    if (iss >> name && name == data.name) {
      data.numLine = currentLine;

      string value;
      while (iss >> value) {
        data.str += value + " ";
      }
    }
  }

  file.close();
}

void replaceLineInFile(const string &filePath, int lineNumber,
                       const string &newLine) {
  ifstream inputFile(filePath);
  ofstream tempFile("temp.txt");
  string line;
  int currentLine = 1;

  assert(inputFile.is_open() && tempFile.is_open());

  while (getline(inputFile, line)) {
    if (currentLine == lineNumber) {
      tempFile << newLine << endl;
    } else {
      tempFile << line << endl;
    }
    currentLine++;
  }

  inputFile.close();
  tempFile.close();

  remove(filePath.c_str());
  rename("temp.txt", filePath.c_str());
}

#ifndef FILE_MANAGER_H // FILE_MANAGER_H
#define FILE_MANAGER_H

#include "utility.h"
#include <fstream>

using namespace std;

void readValuesFromFile(const string &path, Data &data);
void searchLine(const string &filePath);
void replaceLineInFile(const string &filePath, int lineNumber,
                       const string &newLine);

#endif // FILE_MANAGER_H

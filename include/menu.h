#ifndef MENU_H // MENU_H
#define MENU_H

#include "arr.h"
#include "hash_table.h"
#include "list.h"
#include "queue.h"
#include "stack.h"
#include "tree.h"

#include <any>
#include <cassert>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

void mMenu(map<string, any> &mp, const vector<string> tokens);
size_t stringToSize(const string &str);

#endif // MENU_H

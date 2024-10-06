#ifndef MENU_H // MENU_H
#define MENU_H

#include "arr.h"
#include "hash_table.h"
#include "list.h"
#include "queue.h"
#include "stack.h"
#include "tree.h"

#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

void mMenu(HNode &ht, Node *tokens, Data &data);
size_t stringToSize(const string &str);

#endif // MENU_H

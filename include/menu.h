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

void mMenu(Node *tokens, Data &data);
void slMenu(Node *tokens, Data &data);
void dlMenu(Node *tokens, Data &data);
void qMenu(Node *tokens, Data &data);
void sMenu(Node *tokens, Data &data);
void hMenu(Node *tokens, Data &data);
void tMenu(Node *tokens, Data &data);
void addToData(Data &data, TNode *node);
size_t stringToSize(const string &str);
Node *parse(const string &input);

#endif // MENU_H

#ifndef TREE_H // TREE_H
#define TREE_H

#include "utility.h"

struct TNode {
  string key;
  int height;
  TNode *left;
  TNode *right;
};

int height(TNode *node);
int bFactor(TNode *node);
void fixHeight(TNode *node);
TNode *rotateRight(TNode *node);
TNode *rotateLeft(TNode *node);
TNode *balance(TNode *node);
TNode *insert(TNode *node, const string value);
TNode *findValue(TNode *node, const string value);
TNode *removeValue(TNode *node, const string value);
TNode *findMin(TNode *node);
TNode *removeMin(TNode *node);
void printTree(TNode *node);
void freeTree(TNode *node);

#endif // TREE_H

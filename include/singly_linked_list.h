#ifndef SINGLY_LINKED_LIST // SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include "utility.h"
#include <cassert>

struct Node {
  char data;
  Node *next;
};

void addHead(Node *&node, char value);
void addTail(Node *&node, char value);
void removeHead(Node *&node);
void removeTail(Node *&node);
void removeValue(Node *&node, char target);
Node **findValue(Node *node, char target);
void printList(Node *node);
void freeList(Node *&node);

#endif // SINGLY_LINKED_LIST

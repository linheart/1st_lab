#ifndef LIST_H // LIST_H
#define LIST_H

#include "utility.h"
#include <cassert>

struct Node {
  char data;
  Node *next;
  Node *prev;
};

struct SinglyLinkedList {
  void addHead(Node *&node, char value);
  void addTail(Node *&node, char value);
  void removeTail(Node *&node);
  void removeValue(Node *&node, char target);
  Node **findValue(Node *&node, char target);
  void removeHead(Node *&node);
  void printList(Node *node);
  void freeList(Node *&node);
};

struct DoublyLinkedList {
  void addHead(Node *&node, char value);
  void addTail(Node *&node, char value);
  void removeHead(Node *&node);
  void removeTail(Node *&node);
  void removeValue(Node *&node, char target);
  Node **findValue(Node *&node, char target);
  void printList(Node *node);
  void freeList(Node *&node);
};

#endif // LIST_H

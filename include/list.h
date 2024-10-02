#ifndef LIST_H // LIST_H
#define LIST_H

#include "utility.h"

struct SinglyLinkedList {
  void addHead(Node *&node, const string value);
  void addTail(Node *&node, const string value);
  void removeTail(Node *&node);
  void removeValue(Node *&node, const string target);
  Node **findValue(Node *&node, const string target);
  void removeHead(Node *&node);
  void printList(Node *node);
  void freeList(Node *&node);
};

struct DoublyLinkedList {
  void addHead(Node *&node, const string value);
  void addTail(Node *&node, const string value);
  void removeHead(Node *&node);
  void removeTail(Node *&node);
  void removeValue(Node *&node, const string target);
  Node **findValue(Node *&node, const string target);
  void printList(Node *node);
  void freeList(Node *&node);
};

#endif // LIST_H

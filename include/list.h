#ifndef LIST_H // LIST_H
#define LIST_H

#include "utility.h"

struct Node {
  string data;
  Node *next;
  Node *prev;
};

struct SinglyLinkedList {
  void addHead(Node *&node, string value);
  void addTail(Node *&node, string value);
  void removeTail(Node *&node);
  void removeValue(Node *&node, string target);
  Node **findValue(Node *&node, string target);
  void removeHead(Node *&node);
  void printList(Node *node);
  void freeList(Node *&node);
};

struct DoublyLinkedList {
  void addHead(Node *&node, string value);
  void addTail(Node *&node, string value);
  void removeHead(Node *&node);
  void removeTail(Node *&node);
  void removeValue(Node *&node, string target);
  Node **findValue(Node *&node, string target);
  void printList(Node *node);
  void freeList(Node *&node);
};

#endif // LIST_H

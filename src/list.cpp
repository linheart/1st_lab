#include "../include/singly_linked_list.h"

void addHead(Node *&node, char value) {
  Node *newNode = new Node{value, node};
  node = newNode;
}

void addTail(Node *&node, char value) {
  Node *newNode = new Node{value, nullptr};
  Node **curNode = &node;

  while (*(curNode)) {
    curNode = &(*curNode)->next;
  }

  *curNode = newNode;
}

void removeHead(Node *&node) {
  assert(node);

  Node *tmp = node;
  node = node->next;
  delete tmp;
}

void removeTail(Node *&node) {
  Node **curNode = &node;

  assert(*curNode);

  while ((*curNode)->next) {
    curNode = &(*curNode)->next;
  }

  delete (*curNode);
  (*curNode) = nullptr;
}

void removeValue(Node *&node, char target) {
  Node **curNode = findValue(node, target);
  Node *tmp = *curNode;

  *curNode = (*curNode)->next;
  delete tmp;
}

Node **findValue(Node *node, char target) {
  Node **curNode = &node;

  while (*(curNode) && (*curNode)->data != target) {
    curNode = &(*curNode)->next;
  }

  assert(*curNode);

  return curNode;
}

void printList(Node *node) {
  Node *curNode = node;

  while (curNode) {
    cout << curNode->data;
    curNode = curNode->next;
  }
  cout << endl;
}

void freeList(Node *&node) {
  Node *tmp = node;

  while (node) {
    tmp = node;
    node = node->next;
    delete tmp;
  }
}
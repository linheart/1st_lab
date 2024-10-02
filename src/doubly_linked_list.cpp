#include "../include/list.h"

void DoublyLinkedList::addHead(Node *&node, const string value) {
  Node *newNode = new Node{value, node, nullptr};
  if (node) {
    node->prev = newNode;
  }
  node = newNode;
}

void DoublyLinkedList::addTail(Node *&node, const string value) {
  Node *newNode = new Node{value, nullptr, nullptr};
  Node **curNode = &node;

  while ((*curNode)->next) {
    curNode = &(*curNode)->next;
  }

  (*curNode)->next = newNode;
  newNode->prev = (*curNode);
}

void DoublyLinkedList::removeHead(Node *&node) {
  assert(node);

  Node *tmp = node;
  node = node->next;

  if (node) {
    node->prev = nullptr;
  }
  delete tmp;
}

void DoublyLinkedList::removeTail(Node *&node) {
  assert(node);

  Node **curNode = &node;

  while ((*curNode)->next) {
    curNode = &(*curNode)->next;
  }

  delete (*curNode);
  (*curNode) = nullptr;
}

void DoublyLinkedList::removeValue(Node *&node, const string target) {
  Node **curNode = DoublyLinkedList::findValue(node, target);
  Node *tmp = *curNode;

  *curNode = tmp->next;

  if (tmp->prev) {
    tmp->prev->next = *curNode;
  }

  if (*curNode) {
    (*curNode)->prev = tmp->prev;
  }

  delete tmp;
}

Node **DoublyLinkedList::findValue(Node *&node, const string target) {
  Node **curNode = &node;

  while (*(curNode) && (*curNode)->data != target) {
    curNode = &(*curNode)->next;
  }

  return curNode;
}

void DoublyLinkedList::printList(Node *node) {
  Node *curNode = node;

  while (curNode) {
    cout << curNode->data << endl;
    curNode = curNode->next;
  }
}

void DoublyLinkedList::freeList(Node *&node) {
  Node *curNode = node;
  while (curNode) {
    Node *nextNode = curNode->next;
    delete curNode;
    curNode = nextNode;
  }
  node = nullptr;
}

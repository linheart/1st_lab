#include "../include/list.h"

void SinglyLinkedList::addHead(Node *&node, string value) {
  Node *newNode = new Node{value, node};
  node = newNode;
}

void SinglyLinkedList::addTail(Node *&node, string value) {
  Node *newNode = new Node{value, nullptr};
  Node **curNode = &node;

  while (*(curNode)) {
    curNode = &(*curNode)->next;
  }

  *curNode = newNode;
}

void SinglyLinkedList::removeHead(Node *&node) {
  assert(node);

  Node *tmp = node;
  node = node->next;
  delete tmp;
}

void SinglyLinkedList::removeTail(Node *&node) {
  assert(node);

  Node **curNode = &node;

  while ((*curNode)->next) {
    curNode = &(*curNode)->next;
  }

  delete (*curNode);
  (*curNode) = nullptr;
}

void SinglyLinkedList::removeValue(Node *&node, string target) {
  Node **curNode = SinglyLinkedList::findValue(node, target);
  Node *tmp = *curNode;

  *curNode = (*curNode)->next;
  delete tmp;
}

Node **SinglyLinkedList::findValue(Node *&node, string target) {
  Node **curNode = &node;

  while (*(curNode) && (*curNode)->data != target) {
    curNode = &(*curNode)->next;
  }

  assert(*curNode);

  return curNode;
}

void SinglyLinkedList::printList(Node *node) {
  Node *curNode = node;

  while (curNode) {
    cout << curNode->data << endl;
    curNode = curNode->next;
  }
}

void SinglyLinkedList::freeList(Node *&node) {
  Node *tmp = node;

  while (node) {
    tmp = node;
    node = node->next;
    delete tmp;
  }
}

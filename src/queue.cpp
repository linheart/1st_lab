#include "../include/queue.h"

void push(Queue &q, const string &value) {
  Node *newNode = new Node{value, nullptr};

  if (!q.front) {
    q.front = newNode;
    q.rear = newNode;
  } else {
    q.rear->next = newNode;
    q.rear = newNode;
  }
}

void pop(Queue &q) {
  assert(q.front);

  Node *tmp = q.front;
  q.front = q.front->next;

  if (!q.front) {
    q.rear = nullptr;
  }

  delete tmp;
}

string front(Queue &q) {
  assert(q.front);
  return q.front->data;
}

bool isEmpty(Queue &q) { return q.front == nullptr; }

void clearQueue(Queue &q) {
  while (!isEmpty(q)) {
    pop(q);
  }
}

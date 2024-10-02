#ifndef QUEUE_H // QUEUE_H
#define QUEUE_H

#include "utility.h"

struct Queue {
  Node *front;
  Node *rear;
};

void push(Queue &q, const string &value);
void pop(Queue &q);
string front(Queue &q);
bool isEmpty(Queue &q);
void clearQueue(Queue &q);

#endif // QUEUE_H

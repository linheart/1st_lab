#ifndef STACK_H // STACK_H
#define STACK_H

#include "utility.h"

struct Stack {
  Node *top;
};

void push(Stack &s, const string &value);
void pop(Stack &s);
string top(Stack &s);
bool isEmpty(Stack &s);
void clearStack(Stack &s);

#endif // STACK_H

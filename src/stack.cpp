#include "../include/stack.h"

void push(Stack &s, const string &value) {
  Node *newNode = new Node{value, s.top};
  s.top = newNode;
}

void pop(Stack &s) {
  assert(s.top);

  Node *tmp = s.top;
  s.top = s.top->next;

  delete tmp;
}

string top(Stack &s) {
  assert(s.top);
  return s.top->data;
}

bool isEmpty(Stack &s) { return s.top == nullptr; }

void clearStack(Stack &s) {
  while (!isEmpty(s)) {
    pop(s);
  }
}

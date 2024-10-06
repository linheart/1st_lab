#ifndef UTILITY_H // UTILITY_H
#define UTILITY_H

#include <cassert>
#include <iostream>

using namespace std;

struct Node {
  string data;
  Node *next;
  Node *prev;
};

struct Data {
  string name;
  string str;
  int numLine;
};

#endif // UTILITY_H

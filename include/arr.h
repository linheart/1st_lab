#ifndef ARR_H // ARR_H
#define ARR_H

#include "utility.h"

struct Array {
  string *data;
  size_t capacity;
  size_t length;
};

void resizeArray(Array *arr, size_t newCapacity);
void append(Array *arr, string value);
void insert(Array *arr, size_t index, string value);
string get(Array *arr, size_t index);
void remove(Array *arr, size_t index);
void replace(Array *arr, size_t index, string value);
size_t length(Array *arr);
void readArray(Array *arr);
void freeArray(Array *arr);

#endif // ARR_H

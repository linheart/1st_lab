#ifndef ARR_H // ARR_H
#define ARR_H

#include "utility.h"
#include <cstring>

struct Array {
  char *data;
  size_t capacity;
  size_t length;
};

void resizeArray(Array *arr, size_t newCapacity);
void append(Array *arr, const char value);
void insert(Array *arr, size_t index, const char value);
char get(Array *arr, size_t index);
void remove(Array *arr, size_t index);
void replace(Array *arr, size_t index, int value);
size_t length(Array *arr);
void readArray(Array *arr);
void checkIndex(Array *arr, size_t index);

#endif // ARR_H

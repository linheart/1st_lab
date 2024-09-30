#include "../include/arr.h"

void resizeArray(Array *arr, size_t newCapacity) {
  char *newData = new char[newCapacity];
  memmove(newData, arr->data, arr->length * sizeof(char));
  delete[] arr->data;
  arr->data = newData;
  arr->capacity = newCapacity;
}

void append(Array *arr, const char value) {
  if (arr->length >= arr->capacity) {
    resizeArray(arr, arr->capacity * 2);
  }
  arr->data[arr->length++] = value;
}

void insert(Array *arr, size_t index, const char value) {
  checkIndex(arr, index);
  if (arr->length >= arr->capacity) {
    resizeArray(arr, arr->capacity * 2);
  }
  memmove(arr->data + index + 1, arr->data + index,
          (arr->length - index) * sizeof(char));
  arr->data[index] = value;
  arr->length++;
}

char get(Array *arr, size_t index) {
  checkIndex(arr, index);
  return arr->data[index];
}

void remove(Array *arr, size_t index) {
  checkIndex(arr, index);
  memmove(arr->data + index, arr->data + index + 1,
          (arr->length - index - 1) * sizeof(char));
  arr->length--;
  arr->data[arr->length] = '\0';
}

void replace(Array *arr, size_t index, int value) {
  checkIndex(arr, index);
  arr->data[index] = value;
}

size_t length(Array *arr) { return arr->length; }

void readArray(Array *arr) {
  for (size_t i = 0; i < arr->data[i]; i++) {
    cout << arr->data[i];
  }
  cout << endl;
}

void checkIndex(Array *arr, size_t index) {
  if (index >= arr->length) {
    cerr << "Index out of range." << endl;
    exit(1);
  }
}

#include "../include/arr.h"

void resizeArray(Array *arr, size_t newCapacity) {
  string *newData = new string[newCapacity];
  size_t size = arr->length;

  for (size_t i = 0; i < size; i++) {
    newData[i] = arr->data[i];
  }

  delete[] arr->data;
  arr->data = newData;
  arr->capacity = newCapacity;
}

void append(Array *arr, string value) {
  if (arr->length >= arr->capacity) {
    resizeArray(arr, arr->capacity * 2);
  }
  arr->data[arr->length++] = value;
}

void insert(Array *arr, size_t index, string value) {
  assert(index <= arr->length);

  if (arr->length >= arr->capacity) {
    resizeArray(arr, arr->capacity * 2);
  }

  for (size_t i = arr->length; i > index; i--) {
    arr->data[i] = arr->data[i - 1];
  }

  arr->data[index] = value;
  arr->length++;
}

string get(Array *arr, size_t index) {
  assert(index < arr->length);
  return arr->data[index];
}

void remove(Array *arr, size_t index) {
  assert(index < arr->length);
  size_t size = arr->length;
  for (size_t i = index; i < size - 1; i++) {
    arr->data[i] = arr->data[i + 1];
  }

  arr->length--;
}

void replace(Array *arr, size_t index, string value) {
  assert(index < arr->length);
  arr->data[index] = value;
}

size_t length(Array *arr) { return arr->length; }

void readArray(Array *arr) {
  size_t size = arr->length;
  for (size_t i = 0; i < size; i++) {
    cout << arr->data[i] << endl;
  }
}

void freeArray(Array *arr) {
  delete[] arr->data;
  delete arr;
}

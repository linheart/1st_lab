#include "../include/menu.h"

void mMenu(HNode &ht, Node *tokens, Data &data) {
  ht.type = "Array";

  string query = tokens->data;
  string name = tokens->next->data;

  Array *arr = new Array{nullptr, 2, 0};
  arr->data = new string[arr->capacity];
  ht.value = arr;

  if (data.str[0]) {
    stringstream stream(data.str);
    string word;
    while (stream >> word) {
      append(arr, word);
    }
  }

  if (query == "MPUSH") {
    string value = tokens->next->next->data;
    append(arr, value);
  } else if (query == "MINSERT") {
    size_t index = stringToSize(tokens->next->next->data);
    string value = tokens->next->next->next->data;
    insert(arr, index, value);
  } else if (query == "MGET") {
    size_t index = stringToSize(tokens->next->next->data);
    cout << get(arr, index) << endl;
  } else if (query == "MREPLACE") {
    size_t index = stringToSize(tokens->next->next->data);
    string value = tokens->next->next->next->data;

    replace(arr, index, value);
  } else if (query == "MDEL") {
    size_t index = stringToSize(tokens->next->next->data);

    remove(arr, index);
  } else if (query == "MLEN") {
    cout << length(arr) << endl;
  } else {
    cout << "Wrong query" << endl;
  }

  data.str.clear();
  data.str += data.name + " ";
  for (size_t i = 0; i < arr->length; i++) {
    data.str += arr->data[i] + " ";
  }
}

size_t stringToSize(const string &str) {
  stringstream stream(str);
  size_t res;
  stream >> res;

  return res;
}

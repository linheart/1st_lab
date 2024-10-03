#include "../include/menu.h"

void mMenu(map<string, any> &mp, const vector<string> tokens) {
  string query = tokens[0];
  string name = tokens[1];

  if (!mp.count(name)) {
    mp[name] = Array{nullptr, 2, 0};
    any_cast<Array &>(mp[name]).data = new string[2];
  }

  Array &arr = any_cast<Array &>(mp[name]);

  if (query == "MPUSH") {
    string value = tokens[2];
    append(&arr, value);
  } else if (query == "MINSERT") {
    size_t index = stringToSize(tokens[2]);
    string value = tokens[3];

    insert(&arr, index, value);
  } else if (query == "MGET") {
    size_t index = stringToSize(tokens[2]);
    cout << get(&arr, index) << endl;
  } else if (query == "MREPLACE") {
    size_t index = stringToSize(tokens[2]);
    string value = tokens[3];

    replace(&arr, index, value);
  } else if (query == "MDEL") {
    size_t index = stringToSize(tokens[2]);

    remove(&arr, index);
  } else if (query == "MLEN") {
    cout << length(&arr) << endl;
  } else {
    cout << "Wrong query" << endl;
  }
}

size_t stringToSize(const string &str) {
  stringstream stream(str);
  size_t res;
  stream >> res;

  return res;
}

#include "../include/hash_table.h"

unsigned hashFunction(const string &key) {
  unsigned hash = 0;
  for (auto ch : key) {
    hash = (hash * 31 + ch) % TABLE_SIZE;
  }
  return hash;
}

void initHashTable(HashTable &ht) {
  ht.table = new HNode *[TABLE_SIZE];
  for (size_t i = 0; i < TABLE_SIZE; i++) {
    ht.table[i] = nullptr;
  }
}

void insert(HashTable &ht, const string &key, void *value, const string &type) {
  unsigned index = hashFunction(key);
  HNode *newNode = new HNode{key, value, ht.table[index], type};
  ht.table[index] = newNode;
}

void *get(HashTable &ht, const string &key) {
  unsigned index = hashFunction(key);
  HNode *curNode = ht.table[index];

  while (curNode && curNode->key != key) {
    curNode = curNode->next;
  }

  return curNode ? curNode->value : nullptr;
}

void remove(HashTable &ht, const string &key) {
  unsigned index = hashFunction(key);
  HNode *curNode = ht.table[index];
  HNode *tmp = nullptr;

  while (curNode && curNode->key != key) {
    tmp = curNode;
    curNode = curNode->next;
  }

  assert(curNode);

  if (tmp) {
    tmp->next = curNode->next;
  } else {
    ht.table[index] = curNode->next;
  }

  delete curNode;
}

void clearHashTable(HashTable &ht) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    HNode *current = ht.table[i];
    while (current != nullptr) {
      HNode *temp = current;
      current = current->next;
      delete temp;
    }
    ht.table[i] = nullptr;
  }
  delete[] ht.table;
}

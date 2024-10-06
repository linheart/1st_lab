#ifndef HASH_TABLE_H // HASH_TABLE_H
#define HASH_TABLE_H

#include "utility.h"

const size_t TABLE_SIZE = 100;

struct HNode {
  string key;
  void *value;
  HNode *next;
  string type;
};

struct HashTable {
  HNode **table;
};

unsigned hashFunction(const string &key);
void initHashTable(HashTable &ht);
void insert(HashTable &ht, const string &key, void *value, const string &type);
void *get(HashTable &ht, const string &key);
void remove(HashTable &ht, const string &key);
void clearHashTable(HashTable &ht);

#endif // HASH_TABLE_H

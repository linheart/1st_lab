#ifndef HASH_TABLE_H // HASH_TABLE_H
#define HASH_TABLE_H

#include "utility.h"

const int TABLE_SIZE = 100;

struct HNode {
  string key;
  string value;
  HNode *next;
};

struct HashTable {
  HNode **table;
};

unsigned hashFunction(const string &key);
void initHashTable(HashTable &ht);
void insert(HashTable &ht, const string &key, const string &value);
string get(HashTable &ht, const string &key);
void remove(HashTable &ht, const string &key);
void clearHashTable(HashTable &ht);

#endif // HASH_TABLE_H

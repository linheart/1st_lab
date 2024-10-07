#include "../include/menu.h"

void mMenu(Node *tokens, Data &data) {

  string query = tokens->data;
  string name = tokens->next->data;

  Array *arr = new Array{nullptr, 2, 0};
  arr->data = new string[arr->capacity];

  if (data.str[0]) {
    istringstream stream(data.str);
    string word;
    while (stream >> word) {
      append(arr, word);
    }
  }

  if (query == "MPUSH") {
    append(arr, tokens->next->next->data);
  } else if (query == "MINSERT") {
    size_t index = stringToSize(tokens->next->next->data);
    insert(arr, index, tokens->next->next->next->data);
  } else if (query == "MGET") {
    size_t index = stringToSize(tokens->next->next->data);
    cout << get(arr, index) << endl;
  } else if (query == "MREPLACE") {
    size_t index = stringToSize(tokens->next->next->data);
    replace(arr, index, tokens->next->next->next->data);
  } else if (query == "MDEL") {
    size_t index = stringToSize(tokens->next->next->data);
    remove(arr, index);
  } else if (query == "MLEN") {
    cout << length(arr) << endl;
  } else {
    cout << "Wrong query" << endl;
  }

  data.str.clear();
  if (arr->length) {
    data.str += data.name + " ";
    for (size_t i = 0; i < arr->length; i++) {
      data.str += arr->data[i] + " ";
    }
  }

  freeArray(arr);
}

void slMenu(Node *tokens, Data &data) {
  string query = tokens->data;
  string name = tokens->next->data;
  SinglyLinkedList SList;
  Node *node = nullptr;

  if (data.str[0]) {
    node = parse(data.str);
  }

  if (query == "SLPUSH") {
    SList.addTail(node, tokens->next->next->data);
  } else if (query == "SLADD") {
    SList.addHead(node, tokens->next->next->data);
  } else if (query == "SLREM") {
    SList.removeTail(node);
  } else if (query == "SLDEL") {
    SList.removeHead(node);
  } else if (query == "SLREMV") {
    SList.removeValue(node, tokens->next->next->data);
  } else {
    cout << "Wrong query" << endl;
  }

  data.str.clear();

  Node *curNode = node;
  if (curNode) {
    data.str += data.name + " ";
    while (curNode) {
      data.str += curNode->data + " ";
      curNode = curNode->next;
    }
  }
  SList.freeList(node);
}

void dlMenu(Node *tokens, Data &data) {
  string query = tokens->data;
  string name = tokens->next->data;
  DoublyLinkedList DList;
  Node *node = nullptr;

  if (data.str[0]) {
    node = parse(data.str);
  }

  if (query == "DLPUSH") {
    DList.addTail(node, tokens->next->next->data);
  } else if (query == "DLADD") {
    DList.addHead(node, tokens->next->next->data);
  } else if (query == "DLREM") {
    DList.removeTail(node);
  } else if (query == "DLDEL") {
    DList.removeHead(node);
  } else if (query == "DLREMV") {
    DList.removeValue(node, tokens->next->next->data);
  } else {
    cout << "Wrong query" << endl;
  }

  data.str.clear();

  Node *curNode = node;
  if (curNode) {
    data.str += data.name + " ";
    while (curNode) {
      data.str += curNode->data + " ";
      curNode = curNode->next;
    }
  }
  DList.freeList(node);
}

void qMenu(Node *tokens, Data &data) {
  string query = tokens->data;
  string name = tokens->next->data;
  Queue *node = new Queue{nullptr, nullptr};

  if (data.str[0]) {
    istringstream stream(data.str);
    string word;
    while (stream >> word) {
      push(*node, word);
    }
  }
  if (query == "QPUSH") {
    push(*node, tokens->next->next->data);
  } else if (query == "QPOP") {
    pop(*node);
  } else {
    cout << "Wrong query" << endl;
  }

  data.str.clear();
  if (!isEmpty(*node)) {
    data.str += data.name + " ";
    while (!isEmpty(*node)) {
      data.str += front(*node) + " ";
      pop(*node);
    }
  }

  clearQueue(*node);
  delete node;
}

void sMenu(Node *tokens, Data &data) {
  string query = tokens->data;
  string name = tokens->next->data;
  Stack *node = new Stack{nullptr};
  if (data.str[0]) {
    istringstream stream(data.str);
    string word;
    while (stream >> word) {
      push(*node, word);
    }
  }
  if (query == "SPUSH") {
    push(*node, tokens->next->next->data);
  } else if (query == "SPOP") {
    pop(*node);
  } else {
    cout << "Wrong query" << endl;
  }

  data.str.clear();
  if (!isEmpty(*node)) {
    data.str += data.name + " ";
    while (!isEmpty(*node)) {
      data.str += top(*node) + " ";
      pop(*node);
    }
  }
  clearStack(*node);
  delete node;
}

void hMenu(Node *tokens, Data &data) {
  string query = tokens->data;
  string name = tokens->next->data;
  HashTable node;
  initHashTable(node);

  Array *arr = new Array{nullptr, 2, 0};
  arr->data = new string[arr->capacity];

  insert(node, name, arr, "Array");

  if (data.str[0]) {
    istringstream stream(data.str);
    string word;
    while (stream >> word) {
      append(arr, word);
    }
  }

  if (query == "HADD") {
    insert(node, name, &tokens->next->next->data, "string");
  } else if (query == "HGET") {
    assert(arr->data);
    if (static_cast<Array *>(get(node, name))) {
      cout << true << endl;
    } else {
      cout << false << endl;
    }
  } else if (query == "HDEL") {
    remove(node, name);
  } else {
    cout << "Wrong query" << endl;
  }

  data.str.clear();
  void *a = get(node, name);
  data.str = a ? data.name + " " + *static_cast<Array *>(a)->data : "";
  freeArray(arr);
  clearHashTable(node);
}

void tMenu(Node *tokens, Data &data) {
  string query = tokens->data;
  string name = tokens->next->data;
  TNode *node = nullptr;

  if (data.str[0]) {
    istringstream stream(data.str);
    string word;
    while (stream >> word) {
      node = insert(node, word);
    }
  }

  if (query == "TPUSH") {
    node = insert(node, tokens->next->next->data);
  } else if (query == "TGET") {
    if (findValue(node, tokens->next->next->data)) {
      cout << true << endl;
    } else {
      cout << false << endl;
    }
  } else if (query == "TDEL") {
    node = removeValue(node, tokens->next->next->data);
  } else {
    cout << "Wrong query" << endl;
  }

  data.str.clear();
  if (node) {
    data.str += data.name + " ";
    addToData(data, node);
  }
  freeTree(node);
}

void addToData(Data &data, TNode *node) {
  if (node) {
    addToData(data, node->left);
    data.str += node->key + " ";
    addToData(data, node->right);
  }
}

Node *parse(const string &input) {
  Node *tokens = nullptr;
  SinglyLinkedList SList;
  istringstream iss(input);
  string token;

  while (iss >> token) {
    SList.addTail(tokens, token);
  }

  return tokens;
}

size_t stringToSize(const string &str) {
  istringstream stream(str);
  size_t res;
  stream >> res;

  return res;
}

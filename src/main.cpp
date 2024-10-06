#include "../include/file_manager.h"
#include "../include/menu.h"

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

void freeStructure(HNode &ht) {
  if (ht.type == "Array") {
    freeArray(static_cast<Array *>(ht.value));
  }
}

void printStructure(HNode &ht, const string key) {
  /*assert(ht);*/

  if (ht.type == "Array") {
    readArray(static_cast<Array *>(ht.value));
  }
}

int main(int argc, char **argv) {
  assert(argc == 5 && string(argv[1]) == "--file" &&
         string(argv[3]) == "--query");

  Data data;
  SinglyLinkedList SList;
  Node *tokens = parse(argv[4]);
  data.name = tokens->next->data;
  HNode ht = {data.name, nullptr, nullptr};

  readValuesFromFile(argv[2], data);

  switch (tokens->data[0]) {
  case 'M':
    mMenu(ht, tokens, data);
    break;
  case 'L':
    break;
  case 'Q':
    break;
  case 'S':
    break;
  case 'H':
    break;
  case 'T':
    break;
  case 'P':
    if (tokens->data == "PRINT") {
      /*printStructure(ht, "h1");*/
      break;
    }
  default:
    cout << "Wrong query" << endl;
    break;
  }

  replaceLineInFile(argv[2], data.numLine, data.str);

  SList.freeList(tokens);
  freeStructure(ht);
  return 0;
}

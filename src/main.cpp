#include "../include/file_manager.h"
#include "../include/menu.h"

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
    mMenu(tokens, data);
    break;
  case 'Q':
    qMenu(tokens, data);
    break;
  case 'S':
    if (tokens->data[1] == 'L') {
      slMenu(tokens, data);
      break;
    }
    sMenu(tokens, data);
    break;
  case 'D':
    dlMenu(tokens, data);
    break;
  case 'H':
    hMenu(tokens, data);
    break;
  case 'T':
    tMenu(tokens, data);
    break;
  case 'P':
    if (tokens->data == "PRINT") {
      cout << data.str << endl;
      break;
    }
  default:
    cout << "Wrong query" << endl;
    break;
  }

  replaceLineInFile(argv[2], data.numLine, data.str);

  SList.freeList(tokens);
  return 0;
}

#include "../include/arr.h"
#include "../include/singly_linked_list.h"

using namespace std;

int main(int argc, char **argv) {
  Node *node;

  /*addTail(node, 't');*/
  addTail(node, 'a');
  addTail(node, 'b');
  addTail(node, 'c');
  addTail(node, 'd');

  printList(node);

  /*cout << findValue(node, 'b')->next->data << endl;*/

  /*removeHead(node);*/
  /*removeValue(node, 'c');*/
  /*printList(node);*/

  freeList(node);

  return 0;

  Array arr = {nullptr, 2, 0};
  arr.data = new char[arr.capacity];

  append(&arr, 108);
  append(&arr, 'l');
  insert(&arr, 1, '1');

  readArray(&arr);

  cout << get(&arr, 2) << endl;

  replace(&arr, 0, 'k');

  readArray(&arr);

  remove(&arr, 2);

  readArray(&arr);

  cout << length(&arr) << endl;

  remove(&arr, 2);

  return 0;
}

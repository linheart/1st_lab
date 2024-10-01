#include "../include/arr.h"
#include "../include/list.h"
#include <thread>

using namespace std;

int main(int argc, char **argv) {
  Node *singlyList;
  SinglyLinkedList sList;

  sList.addTail(singlyList, 'e');
  sList.addTail(singlyList, 'f');

  sList.removeValue(singlyList, 'e');
  sList.removeValue(singlyList, 'f');
  /*sList.addTail(singlyList, 'g');*/
  /*sList.addTail(singlyList, 'h');*/

  /*sList.removeTail(singlyList);*/
  /*sList.removeTail(singlyList);*/

  /*sList.removeHead(singlyList);*/
  /*sList.removeHead(singlyList);*/
  /*sList.removeHead(singlyList);*/

  /*sList.addHead(singlyList, 'd');*/
  /*sList.addHead(singlyList, 'c');*/
  /*sList.addHead(singlyList, 'b');*/
  /*sList.addHead(singlyList, 'a');*/

  sList.printList(singlyList);

  /*removeHead(node);*/
  /*removeValue(node, 'c');*/
  /*printList(node);*/

  sList.freeList(singlyList);

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

/*
   File List.h
   Advertising

 */

#include "Node.cpp"

class List {

  int numElem;
  Node *head;

public:
  List();
  ~List();
  int getNumElem();
  void insertionNode(Node *func);
  void switchLasttofirst();
  int removeLastnode();
  void listAll();

};

/*class BothList:public List {

  List *list1;
  List *list2;

public:
    BothList();
    ~BothList();
    void mergeQeue();
 };
*/

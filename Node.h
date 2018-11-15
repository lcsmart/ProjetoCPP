/*
   File Node.h
   Advertising

 */

 #include <iostream>
 #include <string>

 using namespace std;

class Node {
        int position;
        string advertising;
        Node* next;
public:
        Node();
        string getAdvertising();
        int getPosition();
        Node* getNext();
        void setAdvertising (string);
        void setNext(Node* nxt);
        void setPosition(int);
};

#include "wlist.h"
#include <iostream>
void wlist::print() {
  Node* iter = first;
  while (iter != nullptr) {
     std::cout<<iter->data<<std::endl;
     iter=iter->next;
  }
}
void wlist::push(int data) {
   if (top == nullptr) { 
     top = new Node();
     top->data = data;
     first = top;
     return;
   }
   Node* newNode = new Node();
   newNode->data = data;
   top->next = newNode;
   top = newNode;
}

void wlist::insertAfter(Node* node, int data) {

}

// This operation is needless, we need removeAfter for singlelinked list
bool wlist::remove(int data) {
    Node* iter = first;
    if (top == first) { //one element
       delete top; 
       delete first;
       return true;
    }
    if (first->data == data) { // delete first element
       Node* tmp = first;
       first = first->next;
       delete tmp; 
       return true;
    }
    if (top->data == data) { //remove last
       
    }
    while (iter != nullptr) {
       if (iter->next->data == data) {
          Node* deleteNode = iter->next;
          iter->next = deleteNode->next;
          delete deleteNode;
          return true;
       }
       else {
         iter = iter->next;
       }
    }
    return false;

}


Node* wlist::find(int data) {
    Node* iter = first;
    while (iter != nullptr) {
       if (iter->data == data)
         return iter;
       iter = iter->next;
    }
    return nullptr;
}

wlist::~wlist() {
  while (first) {
   Node* iter = first;
   first = first->next;
   delete iter;
  }
}

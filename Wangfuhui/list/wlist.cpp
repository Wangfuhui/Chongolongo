#include "wlist.h"
#include <iostream>
void wlist::print() {
  Node* iter = m_front;
  while (iter != nullptr) {
     std::cout<<iter->data<<std::endl;
     iter=iter->next;
  }
}
void wlist::push_front(int data) {
   if (m_top == nullptr) { 
     m_top = new Node();
     assert(m_top && "Not enough memory");
     m_top->data = data;
     m_front = m_top;
     m_size++;
     return;
   }
   Node* newNode = new Node();
   assert(m_top && "Not enough memory");
   newNode->data = data;
   newNode->next = m_front;
   m_front = newNode;
   m_size++;
}

void wlist::pop_front() {
  assert(m_size > 0 && "underflow");
  m_size--;
  Node* tmp = m_front;
  m_front = m_front->next;
  delete tmp;
  
}

wlist_iterator wlist::begin() {
   return wlist_iterator(m_front);
}
wlist_iterator wlist::end() {
   return wlist_iterator(nullptr);
}

void wlist::insertAfter(Node* node, int data) {

}

// This operation is needless, we need removeAfter for singlelinked list
bool wlist::remove(int data) {
    if (!m_size) return false;
    Node* iter = m_front;
    if (m_top == m_front) { //one element
       delete m_top; 
       delete m_front;
       m_size--;
       return true;
    }
    if (m_front->data == data) { // delete first element
       Node* tmp = m_front;
       m_front = m_front->next;
       delete tmp; 
       m_size--;
       return true;
    }
    if (m_front->data == data) { //remove last
       
    }
    while (iter != nullptr) {
       if (iter->next->data == data) {
          Node* deleteNode = iter->next;
          iter->next = deleteNode->next;
          m_size--;
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
    Node* iter = m_front;
    while (iter != nullptr) {
       if (iter->data == data)
         return iter;
       iter = iter->next;
    }
    return nullptr;
}

wlist::~wlist() {
  while(m_size > 0)
    pop_front();
}

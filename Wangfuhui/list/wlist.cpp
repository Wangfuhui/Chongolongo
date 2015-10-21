#include "wlist.h"
#include <iostream>

wlist::wlist(const wlist& other) //copy ctor
     : m_front(nullptr),
       m_size(other.m_size)
{
    m_front  = new Node();
    m_front->data = other.m_front->data;
    Node* tmp = m_front;
    Node* other_tmp = other.m_front->next;
    while (other_tmp != nullptr) {
         Node* newNode = new Node();
         newNode->data = other_tmp->data;
         tmp->next = newNode;
         tmp = newNode;
         other_tmp =  other_tmp->next;
        
    } 
}
wlist::wlist(wlist&& other) { //move ctor
   m_front = other.m_front;
   m_size = other.m_size;
   other.m_front = nullptr;
   other.m_size = 0;
}
wlist& wlist::operator= (const wlist& other) { //copy assing
   if (this == &other)
      return *this;
   if (m_size == other.m_size) {
     Node* left_tmp = m_front;
     Node* right_tmp = other.m_front;
     while (left_tmp != nullptr) {
        left_tmp->data = right_tmp->data;
        left_tmp = left_tmp->next;
        right_tmp = right_tmp->next;   
     }
   }else  if (m_size < other.m_size) {
    
     Node* left_tmp = m_front;
     Node* right_tmp = other.m_front;
     Node* connect = left_tmp;
     while (left_tmp != nullptr) {
       connect = left_tmp;
       left_tmp->data = right_tmp->data;
       left_tmp = left_tmp->next;
       right_tmp = right_tmp->next;
     }
     while (right_tmp != nullptr) {
        m_size++;
        Node* node = new Node();
        node->data = right_tmp->data;
        connect->next = node;
        connect = connect->next;
        right_tmp = right_tmp->next;
     }
     assert(m_size == other.m_size && "smth wrong in copy assign");
   } 
   else {
     Node* left_tmp = m_front;
     Node* right_tmp = other.m_front;
     Node* connect = left_tmp;
     while (right_tmp != nullptr) {
        connect = left_tmp;
        left_tmp->data = right_tmp->data;
        left_tmp = left_tmp->next;
        right_tmp = right_tmp->next;
     }
     while (left_tmp != nullptr) {
        Node* tmp = left_tmp;
        left_tmp = left_tmp->next;
        delete tmp;
        m_size--;
     }
     connect->next = nullptr;
     assert(m_size == other.m_size && "smth wrong in copy assign");
   }
   return *this;
  
}
//wlist& wlist::operator= (wlist& other) { //mode assign
   
//}
void wlist::print() {
  Node* iter = m_front;
  while (iter != nullptr) {
     std::cout<<iter->data<<std::endl;
     iter=iter->next;
  }
}
void wlist::push_front(int data) {
   if (m_front == nullptr) { 
     m_front = new Node();
     assert(m_front && "Not enough memory");
     m_front->data = data;
     m_size++;
     return;
   }
   Node* newNode = new Node();
   assert(newNode && "Not enough memory");
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

int wlist::front() {
  assert(m_size > 0 && "empty");
  return m_front->data;
}
wlist_iterator wlist::begin()const {
   return wlist_iterator(m_front);
}
wlist_iterator wlist::end() const {
   return wlist_iterator(nullptr);
}

void wlist::insertAfter(wlist_iterator it, int data) {

}
void wlist::removeAfter(wlist_iterator it) {

}

// This operation is needless, we need removeAfter for singlelinked list
bool wlist::remove(int data) {
    if (!m_size) return false;
    Node* iter = m_front;
    if (m_size == 1 && m_front->data == data) { //one element
       delete m_front;
       m_size--;
       m_front = nullptr; //Do we need this?
       return true;
    }
    if (m_front->data == data) { // delete first element
       Node* tmp = m_front;
       m_front = m_front->next;
       delete tmp; 
       m_size--;
       return true;
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

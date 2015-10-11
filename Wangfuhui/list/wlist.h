#include "iterator.h"
#include <assert.h>
class wlist {
public:
   wlist()
   :m_top(nullptr), 
   m_front(nullptr),
   m_size(0) 
   {};   
   ~wlist();
   void push_front(int data);
   void pop_front();
   wlist_iterator begin();
   wlist_iterator end();
   bool remove(int);
   Node* find(int data);
   void insertAfter(Node* node, int data);
   void print();
private:
   Node* m_top;
   Node* m_front;
   unsigned int m_size;
};

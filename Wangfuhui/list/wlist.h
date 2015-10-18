#include "iterator.h"
#include <assert.h>
class wlist {
public:
   wlist()
      :m_front(nullptr),
      m_size(0) 
      {};
   wlist(const wlist& other); //copy ctor
   wlist(wlist&& other); // move ctor

   wlist& operator = (const wlist& other); //copy assign
   wlist& operator = (wlist&& other); // move assign
   ~wlist();
   void push_front(int data);
   void pop_front();
   int front();
   wlist_iterator begin() const; 
   wlist_iterator end() const;
   bool remove(int);
   Node* find(int data);
   void insertAfter(wlist_iterator it, int data);
   void removeAfter(wlist_iterator it);
   void print();
private:
   //Node* m_top;
   Node* m_front;
   unsigned int m_size;
};

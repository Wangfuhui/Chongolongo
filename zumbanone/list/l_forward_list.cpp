#include "l_forward_list.h"
#include <cassert>
#include <cstdio>
#include <iostream>

list::list()
{
    m_size = 0;

    m_front = new Node;
    m_front = NULL;
    //m_front->ptr = NULL;
}

list::list(const list& lst)
    :m_front(NULL)
{

#ifdef DEBUG
    std::cout << "Copy ctor is called\n";
#endif
    copy(lst);
}
void list::copy(const list& lst)
{
    m_front  = NULL;
    m_size = lst.size();
    Node* it = lst.begin(); //iterator
    Node* curr = new Node;
    curr = NULL;
    while( it != NULL) {
	Node* nd = new Node;
	nd->val = it->val;
	if(m_front == NULL) {
	    m_front = nd;
	    curr = m_front;
	} else {
	    curr->ptr = nd;
	    curr = nd;
	}
	it = it->ptr;
    }
}
list& list::operator=(const list& lst)
{

#ifdef DEBUG
    std::cout << "Copy assignment is called\n";
#endif
    list copyLst(lst);
    copy(copyLst);
    return *this;
}

list::list(list&& lst)
{
#ifdef DEBUG
    std::cout << "Move ctor is called\n";
#endif
    m_size = lst.size();
    Node* it = lst.begin(); //iterator
    Node* curr = new Node;
    curr = NULL;
    while( it != NULL) {
	Node* nd = new Node;
	nd->val = it->val;
	if(m_front == NULL) {
	    m_front = nd;
	    curr = m_front;
	} else {
	    curr->ptr = nd;
	    curr = nd;
	}
	lst.pop_front();
	it = lst.begin(); 
    }
}

list& list::operator=(list&& lst)
{
#ifdef DEBUG
    std::cout << "Move assignment is called\n";
#endif

    m_size = lst.size();
    m_front = NULL;
    Node* it = lst.begin(); //iterator
    Node* curr = new Node;
    curr = NULL;
    while( it != NULL) {
	Node* nd = new Node;
	nd->val = it->val;
	if(m_front == NULL) {
	    m_front = nd;
	    curr = m_front;
	} else {
	    curr->ptr = nd;
	    curr = nd;
	}
	lst.pop_front();
	it = lst.begin(); 
    }

    return *this;
}

list::~list() 
{
    while( m_size != 0) {
	pop_front();
    }
    m_front = NULL;
}

//iterators
Node* list::begin() const
{
    return m_front;
}


//Capacity
bool list::empty() const
{
    if(m_size == 0)
	return true;
    return false;
}
int list::size() const
{
    return m_size;
}

//Modifiers
void list::push_front(int val)
{
    Node* node = new Node;
    node->val = val;
    node->ptr = m_front;
    m_front = node;

    m_size++;
}

void list::pop_front()
{
    assert(m_size>0 && "Out of bound");
    Node* tmp = m_front;
    m_front = m_front->ptr;
    delete tmp;
    m_size--;
}

//Element access
int list::front()
{
    return m_front->val;
}

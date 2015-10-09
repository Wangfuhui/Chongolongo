#include "l_forward_list.h"
#include <cassert>
#include <cstdio>

list::list()
{
    m_size = 0;

    m_back = new Node;
    m_back->ptr = NULL;
    m_front = m_back;
}
list::~list() 
{
    while(m_size>0) {
	pop_front();
    }

}
//operator=()

//iterators
Node* list::begin() 
{
    return m_front;
}

Node* list::end()
{
    return m_back;
}

//Capacity
bool list::empty()
{
    if(m_size == 0)
	return true;
    return false;
}
int list::size()
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

    if(m_size == 0)
	m_back = node;
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

int list::back()
{
    return m_back->val;
}

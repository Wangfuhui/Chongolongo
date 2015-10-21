#include <iostream>
//#include <forward_list>

#include "l_forward_list.h"

void printList(const list& l)
{
    Node* b = l.begin();

    std::cout << l.size();

    while(b != NULL) {
	std::cout << b->val << " , ";
	b = b->ptr;
    }
}


int main()
{
    list l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    std::cout << "The result of push and pop on the size of list:\n";
    std::cout << l.size() << "\n";
    l.push_front(5);
    std::cout << l.size() << "\n";
    l.pop_front();
    l.pop_front();
    l.push_front(6);
    std::cout << l.size() << "\n";

    std::cout << "The front and back operations\n";
    std::cout << "Front element is " << l.front() << "\n";

    std::cout << "The begin and end operations\n";
    printList(l);

    std::cout << std::endl;

    list l2(l);
    l.pop_front();
    printList(l2);
    std::cout << std::endl;
  //  l2.pop_front();
   // std::cout << l2.size();
    
    return 0;
}

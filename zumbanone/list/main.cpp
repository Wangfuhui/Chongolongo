#include <iostream>
//#include <forward_list>

#include "l_forward_list.h"


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
    std::cout << "Back element is " << l.back() << "\n";

    std::cout << "The begin and end operations\n";
    Node* b = l.begin();
    Node* e = l.end();

    while(b != e) {
	std::cout << b->val << " , ";
	b = b->ptr;
    }

    if(b==e) {
	std::cout << b->val;
    }
    std::cout << std::endl;

    list l2;
    l2.pop_front();
    std::cout << l2.size();
    
    return 0;
}

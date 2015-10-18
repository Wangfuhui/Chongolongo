#include "wlist.h"
#include <iostream>
int main() {
   wlist list;
   list.push_front(1);
   list.push_front(2);
   list.push_front(3);
   wlist_iterator it = list.begin();
   //std::cout<<*(it++)<<std::endl;
   //wlist_iterator it1 = list.begin();
   //std::cout<<*(++it1)<<std::endl;
   wlist copy = list;
   //std::cout<<copy.front()<<std::endl;
   copy.pop_front();
   list = copy;
   for (wlist_iterator it = list.begin(); it != list.end(); ++it)
      std::cout<<*it<<std::endl;;
   for (wlist_iterator it = copy.begin(); it != copy.end(); ++it)
      std::cout<<*it<<std::endl;; 
   return 0;
}

#include "wlist.h"
#include <iostream>
int main() {
   wlist list;
   list.push_front(1);
   list.push_front(2);
   list.push_front(3);
   for (wlist_iterator it = list.begin(); it != list.end(); ++it)
      std::cout<<*it<<std::endl;;
   return 0;
}

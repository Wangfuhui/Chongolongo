#include "wlist.h"
int main() {
   wlist* list = new wlist();
   list->push(1);
   list->push(2);
   list->push(3);
   list->print();
   list->remove(3);
   list->print();
   delete list;
   return 0;
}

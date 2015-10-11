#include <assert.h>
#include <algorithm>
struct Node {
   int data;
   Node* next;
};
//Quetsions
// 1. How to implmenet post increment;
// 2. When we need to return by reference (++ and * operators)
// 3. Implement own iterator or derive from std::iterator ??
// 4  const iterators
class wlist_iterator {
public:
   wlist_iterator(): it(nullptr) {};
   explicit wlist_iterator(Node* node): it(node) {};
   wlist_iterator& operator++() {
     assert(it && "out of bounds");
     it = it->next;
     return *this;
   }
   bool operator == (const wlist_iterator& other) {
     return it == other.it;
   }
   bool operator != (const wlist_iterator& other) {
     return it != other.it;
   }
   int& operator*() const { //TODO: When whe should return &??
      return it->data;
   }
private:
  Node* it;
};

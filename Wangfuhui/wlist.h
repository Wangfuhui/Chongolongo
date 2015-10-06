struct Node {
   int data;
   Node* next;
};

class wlist {
public:
   wlist():top(nullptr), first(nullptr) {};   
   ~wlist();
   void push(int data);
   Node* find(int data);
   bool remove(int data);
   void insertAfter(Node* node, int data);
   void print();
private:
   Node* top;
   Node* first;
};

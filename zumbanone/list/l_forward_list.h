#ifndef LFORWARDLIST
#define LFORWARDLIST

struct Node {
    int val;
    Node* ptr;
};

class list {
public:
    list();
    ~list();
    //operator=()
    
    //iterators
    Node* begin();
    Node* end();

    //Capacity
    bool empty();
    int size();

    //Modifiers
    void push_front(int val);
    void pop_front();

    //Element access
    int front();
    int back();

private:
    Node* m_front;
    Node* m_back;
    int m_size;
};
#endif //!LFORWARDLIST

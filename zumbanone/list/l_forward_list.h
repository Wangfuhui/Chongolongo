#ifndef LFORWARDLIST
#define LFORWARDLIST

struct Node {
    int val;
    Node* ptr;
};

class list {
public:
    list();
    list(const list& lst);
    ~list();
//    operator=();
    
    //iterators
    Node* begin() const;
    //Node* end();

    //Capacity
    bool empty() const;
    int size() const;

    //Modifiers
    void push_front(int val);
    void pop_front();

    //Element access
    int front();
    //int back();

private:
    Node* m_front;
    //Node* m_back;
    int m_size;
};
#endif //!LFORWARDLIST

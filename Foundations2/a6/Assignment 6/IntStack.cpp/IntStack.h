#ifndef INTSTACK_H_INCLUDED
#define INTSTACK_H_INCLUDED


class IntStack
{
private:
    struct Node{
         int data;
         Node* next;
    };
    Node* head; //ptr to top

public:
    // Constructor
    IntStack();

    //Destructor
    ~IntStack();

    // Stack operations
    void push(int);
    int pop();
    bool isFull();
    bool isEmpty();
};


#endif // INTSTACK_H_INCLUDED

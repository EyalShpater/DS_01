#ifndef __STACK_H
#define __STACK_H

class ItemNode;
class Item;

class Stack
{
    ItemNode* top;

public:
    Stack();
    ~Stack();

    void MakeEmpty();
    bool IsEmpty() const;
    void Push(const Item& item);
    Item* Pop();
    Item* Top() const;
};


#endif // __STACK_H

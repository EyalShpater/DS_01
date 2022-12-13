#include "stack.h"
#include "item.h"
#include "ItemNode.h"

Stack::Stack()
{
    top = new ItemNode(Item(-1, -1, -1, -1)); // Dummy Head
}

Stack::~Stack()
{
    MakeEmpty();
    delete top;
}

void Stack::MakeEmpty()
{
    ItemNode* curr = top->next;
    ItemNode* temp;

    while (curr!= nullptr)
    {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
}

bool Stack::IsEmpty() const
{
    return top->next == nullptr;
}

void Stack::Push(const Item& data)
{
    top->next = new ItemNode(data, top->next);
}

Item* Stack::Pop()
{
    if (IsEmpty())
        return nullptr;

    ItemNode* temp = top->next;
    top->next = temp->next;
    Item* res = temp->data;
    delete temp;

    return res;
}

Item* Stack::Top() const
{
    if (IsEmpty())
        return nullptr;
    return top->next->data;
}
#include "intList.h"

#include "intNode.h"

const int IntList::DUMMY_VALUE = -1;

IntList::IntList()
{
    head = tail = new IntNode(DUMMY_VALUE, nullptr);
}

IntList::~IntList()
{
    makeEmpty();
    delete head;
}

void IntList::makeEmpty()
{
    while (head->next != nullptr)
        delete head->deleteAfter();
    tail = head;
}

bool IntList::isEmpty() const
{
    return (head == tail);
}

void IntList::insertDataToStart(int data)
{
    IntNode* newNode = new IntNode(data);
    newNode->next = head->next;
    head->next = newNode;

    if (isEmpty())
        tail = newNode;
}
void IntList::insertDataToEnd(int data)
{
    IntNode* newNode = new IntNode(data, nullptr);

    tail->next = newNode;
    tail = newNode;
}

void IntList::insert(int data)
{
    IntNode* newNode;
    IntNode* curr;

    curr = head;

    while(curr->next != nullptr && data > curr->next->data)
        curr = curr->next;

    newNode = new IntNode(data);
    curr->insertAfter(newNode);

    if (newNode->next == nullptr)
        tail = newNode;
}
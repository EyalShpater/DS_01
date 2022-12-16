#ifndef __INT_LIST_H
#define __INT_LIST_H

#include "intNode.h"

class IntList
{
public:
    static const int DUMMY_VALUE;

private:
    IntNode* head;
    IntNode* tail;

public:
    IntList();
    ~IntList();

    IntNode* first() const { return head->next; }
    IntNode* last() const { return tail; }

    void makeEmpty();
    bool isEmpty() const;

    void insert(int data);

private:
    void insertDataToStart(int data);
    void insertDataToEnd(int data);
};

#endif // __INT_LIST_H

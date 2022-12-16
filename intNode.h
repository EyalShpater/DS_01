#ifndef __INT_NODE_H
#define __INT_NODE_H

class IntNode
{
    int data;
    IntNode* next;

    friend class IntList;
public:
    IntNode(int data = 0, IntNode* next = nullptr);

    int getData() const { return data; }
    IntNode* getNext() const { return next; }

    void insertAfter(IntNode* newNode);
    IntNode* deleteAfter();
};


#endif // __INT_NODE_H
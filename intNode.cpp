#include "intNode.h"

IntNode::IntNode(int data, IntNode *next)
{
    this->data = data;
    this->next = next;
}

void IntNode::insertAfter(IntNode* newNode)
{
    newNode->next = next;
    next = newNode;
}

IntNode* IntNode::deleteAfter()
{
    IntNode* toDelete = next;

    if (toDelete == nullptr)
        return nullptr;

    next = toDelete->next;

    return toDelete;
}
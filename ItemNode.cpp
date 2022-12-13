#include "ItemNode.h"

ItemNode::ItemNode(const Item& data, ItemNode* next)
{
    this->data = new Item(data);
    this->next = next;
}

void ItemNode::insertAfter(ItemNode* newNode)
{
    newNode->next = next;
    next = newNode;
}

ItemNode* ItemNode::deleteAfter()
{
    ItemNode* toDelete;

    toDelete = next;

    if (toDelete == nullptr)
        return nullptr;
    next = toDelete->next;
    return toDelete;
}
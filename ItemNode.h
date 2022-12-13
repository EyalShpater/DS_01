#ifndef __ITEM_NODE_H
#define __ITEM_NODE_H

#include "item.h"

class ItemNode
{
    Item* data;
    ItemNode* next;

    friend class Stack;
public:
    ItemNode(const Item& data, ItemNode* next = nullptr);

    const Item* getData() const { return data; }
    const ItemNode* getNext() const { return next; }

    void insertAfter(ItemNode* newNode);
    ItemNode* deleteAfter();
};


#endif // __ITEM_NODE_H

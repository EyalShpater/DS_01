#ifndef __INT_LIST_H
#define __INT_LIST_H

class IntNode;

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

    const IntNode* first() const { return head; }
    const IntNode* last() const { return tail; }

    void makeEmpty();
    bool isEmpty() const;

    void insert(int x);

private:
    void insertDataToStart(int data);
    void insertDataToEnd(int data);
};

#endif // __INT_LIST_H
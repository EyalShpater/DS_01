#ifndef __ITEM_H
#define __ITEM_H

class IntNode;

class Item
{
public:
    enum eCurrLine{START, AFTER_FIRST};

private:
    int currCity;
    int line;
    IntNode* nextWhite;

    friend class Stack;

public:
    Item(int currCity, int line, IntNode* road);

    int getCurrCity() const { return currCity; }
    IntNode* getNextWhite() const { return nextWhite; }
    int getLine() const { return line; }

    void setCurrCity(int city) {currCity = city; }
    void setNextWhite (IntNode* white) { nextWhite = white; }
    void setLine(int line) { this->line = line; }
};

#endif // __ITEM_H

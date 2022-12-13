#ifndef __ITEM_H
#define __ITEM_H

class Item
{
public:
    enum eCurrLine{START, AFTER_FIRST};

private:
    int currCity;
    int dest;
    int nextWhite;
    int line;

    friend class Stack;

public:
    Item(int currCity, int dest, int nextWhite, int line);

    int getCurrCity() const { return currCity; }
    int getDest() const { return dest; }
    int getNextWhite() const { return nextWhite; }
    int getLine() const { return line; }

    void setCurrCity(int city) {currCity = city; }
    void setDest(int dest) { this->dest = dest; }
    void setNextWhite (int white) { nextWhite = white; }
    void setLine(int line) { this->line = line; }
};

#endif // __ITEM_H

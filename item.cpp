#include "item.h"

Item::Item(int currCity, /*int nextWhite,*/ int line, IntNode* nextWhite)
{
    this->currCity = currCity;
    //this->nextWhite = nextWhite;
    this->line = line;
    this->nextWhite = nextWhite;
}
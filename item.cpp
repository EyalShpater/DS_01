#include "item.h"

Item::Item(int currCity, int dest, int nextWhite, int line)
{
    this->currCity = currCity;
    this->dest = dest;
    this->nextWhite = nextWhite;
    this->line = line;
}
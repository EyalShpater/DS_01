#include "country.h"
#include "intList.h"
#include "intNode.h"

const int Country::NOT_FOUND = -1;

Country::Country(int size)
{
    cities = new IntList[size + 1];
    colors = new int[size +1];
    this->size = size + 1;

    for (int i = 0; i < this->size; ++i)
        colors[i] = eColor::WHITE;
}

Country::~Country()
{
    delete[]cities;
}

bool Country::insertRoad(int city1, int city2)
{
    if (city1 > size || city2 > size)
        return false;

    cities[city1].insert(city2);
    cities[city2].insert(city1);
    return true;
}

int Country::TownDistance(int currCity, int dest) const
{
    int distance = NOT_FOUND;
    int nextWhite;
    const IntNode* curr;

    colors[currCity] = eColor::BLACK;
    nextWhite = getWhiteRoad(currCity);
    curr = cities[currCity].first();

    if (currCity == dest)
        return 0;
    else
    {
        if (nextWhite == NOT_FOUND)
            return NOT_FOUND;
        else {
            while (curr != nullptr) {
                if (colors[curr->getData()] == eColor::WHITE)
                    distance = TownDistance(curr->getData(), dest);

                if (distance != NOT_FOUND)
                    return distance + 1;
                curr = curr->getNext();
            }
            return NOT_FOUND;
        }
    }
}

int Country::getWhiteRoad(int city) const
{
    int answer = NOT_FOUND;
    const IntNode* curr;

    curr = cities[city].first();

    while(curr != nullptr && answer == NOT_FOUND)
    {
        if (colors[curr->getData()] == eColor::WHITE)
            answer = curr->getData();
        curr = curr->getNext();
    }

    return answer;
}
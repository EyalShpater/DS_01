#include "country.h"
#include "intList.h"
#include "intNode.h"
#include "stack.h"
#include "item.h"

#include <iostream>
using namespace std;

const int Country::NOT_FOUND = -1;

Country::Country(int size)
{
    cities = new IntList[size + 1];
    colors = new int[size +1];
    this->size = size + 1;
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

void Country::getRoads(int numOfRoads)
{
    for (int i = 1; i <= numOfRoads; ++i)
    {
        int city1, city2;
        cin >> city1 >> city2;

        if (isCityValid(city1) && isCityValid(city2))
            insertRoad(city1, city2);
        else
        {
            cout << "invalid road! try again\n";
            --i;
        }
    }
}

int Country::TownDistance(int currCity, int dest) const
{
    int distance = NOT_FOUND;
    IntNode* nextWhite;
    const IntNode* curr;

    colors[currCity] = eColor::BLACK;
    nextWhite = getWhiteRoad(currCity);
    curr = cities[currCity].first();

    if (currCity == dest)
        return 0;
    else
    {
        if (nextWhite == nullptr)
            return NOT_FOUND;
        else {
            while (curr != nullptr)
            {
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

int Country::TownDistanceIterative(int currCity, int dest) const
{
    Stack s;
    Item *curr;
    int returnValue;

    s.Push(Item(currCity, Item::eCurrLine::START, getWhiteRoad(currCity)));

    while (!s.IsEmpty())
    {
        curr = s.Pop();
        colors[curr->getCurrCity()] = eColor::BLACK;

        if (curr->getLine() == Item::eCurrLine::START)
        {
            if (curr->getCurrCity() == dest)
                returnValue = 0;
            else if (curr->getNextWhite() == nullptr)
                    returnValue = NOT_FOUND;
            else
            {
                curr->setLine(Item::eCurrLine::AFTER_FIRST);
                s.Push(*curr);
                s.Push(Item(curr->getNextWhite()->getData(), Item::eCurrLine::START, getWhiteRoad(curr->getNextWhite()->getData())));
            }
        }
        else if (curr->getLine() == Item::eCurrLine::AFTER_FIRST)
        {
            if (returnValue != NOT_FOUND)
                returnValue++;
            else
            {
                IntNode* nextWhite = getWhiteRoad(curr->getCurrCity());

                if (nextWhite == nullptr)
                    returnValue = NOT_FOUND;
                else
                {
                    s.Push(*curr);
                    s.Push(Item(nextWhite->getData(), Item::eCurrLine::START, getWhiteRoad(nextWhite->getData())));
                }
            }
        }
    }

    return returnValue;
}

void Country::initColors()
{
    for (int i = 0; i < size; ++i)
        colors[i] = eColor::WHITE;
}

bool Country::isCityValid(int city) const
{
    return city >= 1 && city < size;
}

bool isCityValid(int city, int size)
{
    return city >= 1 && city < size;
}

IntNode* Country::getWhiteRoad(int city) const
{
    IntNode* answer = nullptr;
    IntNode* curr;

    curr = cities[city].first();

    while(curr != nullptr && answer == nullptr)
    {
        if (colors[curr->getData()] == eColor::WHITE)
            answer = curr;
        curr = curr->getNext();
    }

    return answer;
}
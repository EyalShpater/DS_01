#include "country.h"
#include "intList.h"
#include "intNode.h"
#include "stack.h"
#include "item.h"

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
    Item* curr;
    const IntNode* iter;
    int returnValue;

    s.Push(Item(currCity, dest, getWhiteRoad(currCity), Item::eCurrLine::START));

    while (!s.IsEmpty())
    {
        curr = s.Pop();

        colors[curr->getCurrCity()] = eColor::BLACK;

        if (curr->getLine() == Item::eCurrLine::START)
        {
            if (curr->getCurrCity() == curr->getDest())
                returnValue = 0;
            else
            {
                if (curr->getNextWhite() == NOT_FOUND)
                    returnValue = NOT_FOUND;
                else
                {
                    iter = cities[curr->getCurrCity()].first();

                    while(iter != nullptr)
                    {
                        if (colors[iter->getData()] == eColor::WHITE)
                        {
                            curr->setLine(Item::eCurrLine::AFTER_FIRST);
                            s.Push(*curr);
                            s.Push(Item (iter->getData(), curr->getDest(), getWhiteRoad(iter->getData()), Item::eCurrLine::START));

                            iter = nullptr;
                        }
                        else
                            iter = iter->getNext();
                    }
                }
            }
        }
        else if (curr->getLine() == Item::eCurrLine::AFTER_FIRST)
        {
            if (returnValue != NOT_FOUND)
                returnValue++;
            else
            {
                iter = cities[curr->getCurrCity()].first();
                colors[curr->getCurrCity()] = eColor::BLACK;
                while(iter != nullptr) {
                    if (colors[iter->getData()] == eColor::WHITE) {
                        curr->setLine(Item::eCurrLine::AFTER_FIRST);
                        s.Push(*curr);
                        s.Push(Item(iter->getData(), curr->getDest(), getWhiteRoad(iter->getData()),
                                    Item::eCurrLine::START));

                        iter = nullptr;
                    } else
                        iter = iter->getNext();
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
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

int Country::TownDistance(int currCity, int dest)
{
    int distance;
    colors[currCity] = eColor::BLACK;

    if (currCity == dest)
        return 0;

    if (cities[currCity])
        return NOT_FOUND;
    else
    {
        while(!cities[currCity].isEmpty())
        {
            if (colors[cities[currCity].first()->getData()] == eColor::WHITE)
                distance = TownDistance(cities[currCity].first()->getData(), dest);

            if (distance != NOT_FOUND)
                return distance + 1;
            return NOT_FOUND;

        }

    }
}

int Country::isAllBlack(int city)
{
    int answer = NOT_FOUND;

    while(!cities[city].isEmpty() && answer != NOT_FOUND)
        if (colors[cities[city].first()->getData()] == eColor::WHITE)
            answer = data;

    return answer;
}
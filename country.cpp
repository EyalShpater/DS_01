#include "country.h"
#include "intList.h"

Country::Country(int size)
{
    cities = new IntList[size + 1];
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
#ifndef __COUNTRY_H
#define __COUNTRY_H

class IntList;

class Country
{
    IntList* cities;
    int size;

public:
    Country(int size);
    ~Country();

    bool insertRoad(int city1, int city2);

};


#endif // __COUNTRY_H

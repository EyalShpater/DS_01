#ifndef __COUNTRY_H
#define __COUNTRY_H

class IntList;

class Country
{
public:
    enum eColor{WHITE, BLACK};
    static const int NOT_FOUND;

private:
    IntList* cities;
    int* colors;
    int size;

public:
    Country(int size);
    ~Country();

    bool insertRoad(int city1, int city2);
    int TownDistance(int currCity, int dest) const;

private:
    int getWhiteRoad(int city) const;
};


#endif // __COUNTRY_H

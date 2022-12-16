#ifndef __COUNTRY_H
#define __COUNTRY_H

class IntList;
class IntNode;

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
    void getRoads(int numOfRoads);
    int TownDistance(int currCity, int dest) const;
    int TownDistanceIterative(int currCity, int dest) const;
    void initColors();

    bool isCityValid(int city) const;
    friend bool isCityValid(int city, int size);

private:
    IntNode* getWhiteRoad(int city) const;
};


#endif // __COUNTRY_H

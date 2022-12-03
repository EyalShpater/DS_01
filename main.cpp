#include <iostream>
using namespace std;

#include "country.h"

int main()
{
    int numOfCities, numOfRoads;

    cout << "Please enter the number of cities" << endl;
    cin >> numOfCities;

    cout << "Please enter the number of roads" << endl;
    cin >> numOfRoads;

    cout << "Please enter the roads" << endl;

    Country c(numOfCities);

    for (int i = 1; i <= numOfRoads; ++i)
    {
        int city1, city2;
        cin >> city1 >> city2;

        c.insertRoad(city1, city2);
    }

    return 0;
}

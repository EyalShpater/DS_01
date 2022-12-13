#include <iostream>
using namespace std;

#include "country.h"

int main()
{
    int numOfCities, numOfRoads;
    int location, destination, distance;

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

    cout << "Enter the cities you want to calculate the distance" << endl;
    cin >> location >> destination;

    distance = c.TownDistance(location, destination);
    cout << "The distance after recursive is: " << distance << endl;

    c.initColors();

    distance = c.TownDistanceIterative(location, destination);
    cout << "The distance after iterative is: " << distance << endl;

    return 0;
}

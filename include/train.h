#pragma once

class Train
{
    char name;
    int departureTime = 0;
    int travelTime = 0;
public:
    Train(int&, int&, int&);
    int getTravel();
    int getDeparture();

    void trainCondition();
};

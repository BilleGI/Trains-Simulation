#include <iostream>
#include "train.h"
#include <thread>
#include <vector>

const int TRAINS(3);

void checkNumber(int& time)
{
    while(true)
    {
        if(time >0)
            break;
        std::cout << "Enter the correct time: ";
        std::cin >> time;
    }
}

void checkNumber(int& time, std::vector<Train>& trains)
{
    if (trains.empty())
        checkNumber(time);
    else
    {
        for(int i = 0; i < trains.size();)
        {
            checkNumber(time);
            if(time == trains[i].getDeparture())
            {
                std::cout << "The departure time should not coincide." << std::endl;
                std::cout << "Enter a new departure time: ";
                std::cin >> time;
                i =0;
            }
            else
                ++i;
        }
    }
}

int main()
{
    std::vector<Train> trains;
    std::cout << "The program simulates the operation of the station." << std::endl;
    for(int i = 0; i < TRAINS; ++i)
    {
        int timeDepature;
        std::cout << "Enter the depature time of " << i << " train: ";
        std::cin >> timeDepature;
        checkNumber(timeDepature, trains);

        int timeTravel;
        std::cout << "Enter the trip time of " << i << " train: ";
        std::cin >> timeTravel;
        checkNumber(timeTravel);

        Train train(i, timeDepature, timeTravel);
        trains.push_back(train);
    }

    std::vector<std::thread> threads;

    for(auto it: trains)
        threads.emplace_back(&Train::trainCondition,it);

    for(int i = 0; i < TRAINS; ++i)
        threads[i].join();

    return 0;
}

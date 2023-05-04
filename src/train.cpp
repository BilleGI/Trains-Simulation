#include "train.h"
#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex station;

enum Name
{
    A = 1,
    B = 2,
    C = 4,
};

Train::Train(int& num, int& depature, int& travel) : departureTime(depature), travelTime(travel)
{
    if(pow(2, num) == Name::A) name = 'A';
    else if(pow(2, num) == Name::B) name = 'B';
    else if(pow(2, num) == Name::C) name = 'C';
}

int Train::getTravel()
{
    return travelTime;
}

int Train::getDeparture()
{
    return departureTime;
}

void Train::trainCondition()
{
    std::this_thread::sleep_for(std::chrono::seconds(departureTime));
    std::cout << "This thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "Train " << name << " started movind towards the station." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(travelTime));
    station.lock();
    std::cout << "Train " << name << " has arrived at the station." << std::endl;
    while(1)
    {
        std::string command;
        std::cout << "To depart from the train station, enter depart: ";
        std::cin >> command;
        if (command == "depart") break;
    }
    station.unlock();
}

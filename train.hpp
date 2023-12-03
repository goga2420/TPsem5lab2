#pragma once
#include <iostream>
#include <string>
class Train
{
public:
    Train();
    friend std::ostream& operator<< (std::ostream& out, Train& object);
    friend std::istream& operator>> (std::istream& in, Train& object);
    Train(std::string& destination, int& train_number, int& departure_time);
    ~Train();
    Train(Train& copy);
    Train& operator =(Train& copy);
    std::string GetDestination();
    int GetTrainNumber();
    int GetDepartureTime();
private:
    std::string destination;
    int train_number;
    int departure_time;
};

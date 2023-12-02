#pragma once
#include <iostream>
#include <string>
#include <exception>
class Train
{
public:
    Train();
    friend std::ostream& operator<< (std::ostream& out, Train& object);
    friend std::istream& operator>> (std::istream& in, Train& object);
    Train(std::string& full_name, std::string& post, int& year_of_admission);
    ~Train();
    Train(Train& copy);
    Train& operator =(Train& copy);
    std::string GetFullName();
    int GetYearOfAdmission();
private:
    std::string full_name_;
    std::string post_;
    int year_of_admission_;
};

#include"train.hpp"

Train::Train(std::string& destination, int& train_number, int& departure_time)
{
    this->destination = destination;
    this->train_number = train_number;
    this->departure_time = departure_time;
}
Train::Train()
{
    std::cout << "";
    destination = "";
    train_number = 0;
    departure_time = 0;
}

Train::Train(Train& copy)
{
    std::cout << "";
    *this = copy;
}

Train::~Train()
{
    std::cout << "";
}

std::string Train::GetDestination()
{
    return this->destination;
}

int Train::GetTrainNumber()
{
    return this->train_number;
}

int Train::GetDepartureTime()
{
    return this->departure_time;
}

Train& Train::operator=(Train& copy)
{
    this->destination = copy.destination;
    this->train_number = copy.train_number;
    this->departure_time = copy.departure_time;
    return *this;
}

std::istream& operator>>(std::istream& in, Train& object)
{
    std::cout << "Enter the data\n";
    std::cout << "Введите пункт назначения: ";
    getchar();
    std::getline(std::cin, object.destination);
    std::cout << "Введите номер поезда: ";
    int number;
    std::cin >> number;
    object.train_number = number;
    int departure;
    std::cout << "Введите время отправления: ";
    std::cin>> departure;
    object.departure_time = departure;
    
    return in;
}

std::ostream& operator<<(std::ostream& out, Train& object)
{
    out << "Пункт назначения: " << object.destination << std::endl;
    out << "Номер поезда: " << object.train_number << std::endl;
    out << "Время отправления: " << object.departure_time << std::endl;
    return out;
}

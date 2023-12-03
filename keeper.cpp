#include "keeper.hpp"

Keeper::Keeper()
{
    std::cout << "";
    object = NULL;
    size = 0;
}

Keeper::~Keeper()
{
    std::cout << "";
    delete[]object;
}

Keeper::Keeper(Train* obj)
{
    std::cout << "";
    object = obj;
    ++size;
}

void Keeper::Push()
{
    Train* temp = new Train[size + 1];
    for (int i = 0; i < size; ++i)
        temp[i] = object[i];
    delete[] object;
    object = temp;
    std::cin >> object[size];
    ++size;
    this->Sort();
    std::cout << "\nAdd new object\n";
}

void Keeper::Pop()
{
    try
    {
        if (size == 0) {
            throw std::invalid_argument("Нулевое значение!");
        }
        int num;
        std::cout << "Chose which element to delete: ";
        std::cin >> num;
        if (num < 0 || num >= size)
        {
            throw std::invalid_argument("Неверное значение!");
        }

        Train* temp = new Train[size - 1];
        for (int i = 0, j = 0; i < num && size>1 && j < size - 1; ++i, ++j)
            temp[j] = object[i];
        for (int i = num + 1, j = num; i < size && size>1 && j < size - 1; ++i)
            temp[j] = object[i];
        delete[] object;
        object = temp;
        --size;
        this->Sort();
        std::cout << "\nObject deleted\n";
    }
    catch (std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
}

void Keeper::Show()
{
    try
    {
        if (size == 0)
        {
            throw std::invalid_argument("Нулевое значение!");
        }
        for (int i = 0; i < size; ++i)
            std::cout << object[i] << std::endl;
    }
    catch (std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
}


void Keeper::Edit(const int& change)
{
    try {
        if (size == 0) {
            throw std::invalid_argument("Нулевой размер!");
        }
        if (change < 0 || change >= size) {
            throw std::invalid_argument("Неверный размер!");
        }
        std::cin >> object[change];
    }
    catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }
}

void Keeper::TrainInfo()
{
    try
    {
        if (size == 0) {
            
            throw std::invalid_argument("Нулевое значение!");
        }
        bool flag = false;
        std::string destination;
        std::cout<<std::endl;
        std::cout<<"Введите интересующий пункт назначения"<< std::endl;
        std::getchar();
        std::getline(std::cin, destination);
        for (int i = 0; i < size; i++)
        {
            if (object[i].GetDestination() == destination)
            {
                flag = true;
                std::cout << "Номер поезда: " << object[i].GetTrainNumber() << '\n' << "Пункт назначения: " <<  object[i].GetDestination() << '\n' << "Время отправления: " << object[i].GetDepartureTime() << std::endl;
                std::cout << std::endl;
            }
        }
        if (!flag)
        {
            std::cout << "Нет доступных поездов"<< std::endl;
            std::cout << std::endl;
        }
    }
    catch (std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
}

void Keeper::Sort()
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i- 1; ++j)
        {
            if (object[j].GetDepartureTime()>object[j + 1].GetDepartureTime())
            {
                Train temp = object[j];
                object[j] = object[j + 1];
                object[j + 1] = temp;
            }
        }
    }
}

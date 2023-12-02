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
            std::exception empty("Object is empty");
            throw empty;
        }
        int num;
        std::cout << "Chose which element to delete: ";
        std::cin >> num;
        if (num < 0 || num >= size)
        {
            std::exception wrong("Wrong value");
            throw wrong;
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
            std::exception empty("Object is empty");
            throw empty;
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
            std::exception empty("Object is empty");
            throw empty;
        }
        if (change < 0 || change >= size) {
            std::exception wrong("Wrong value");
            throw wrong;
        }
        std::cin >> object[change];
    }
    catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }
}

void Keeper::BestExperience(int exp)
{
    try
    {
        if (size == 0) {
            std::exception empty("Object is empty");
            throw empty;
        }
        int this_year = 2023;
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            if (this_year - object[i].GetYearOfAdmission() > exp)
            {
                flag = true;
                std::cout << object[i].GetFullName() << std::endl;
            }
        }
        if (!flag)
        {
            std::cout << "";
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
            if (object[j].GetFullName()>object[j + 1].GetFullName())
            {
                Worker temp = object[j];
                object[j] = object[j + 1];
                object[j + 1] = temp;
            }
        }
    }
}

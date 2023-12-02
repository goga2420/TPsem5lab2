#include"train.hpp"

Train::Train(std::string& full_name, std::string& post, int& year_of_admission)
{
    this->full_name_ = full_name;
    this->post_ = post;
    this->year_of_admission_ = year_of_admission;
}
Train::Train()
{
    std::cout << "";
    full_name_ = "";
    post_ = "";
    year_of_admission_ = 0;
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

std::string Train::GetFullName()
{
    return this->full_name_;
}

int Train::GetYearOfAdmission()
{
    return this->year_of_admission_;
}

Train& Train::operator=(Train& copy)
{
    this->full_name_ = copy.full_name_;
    this->post_ = copy.post_;
    this->year_of_admission_ = copy.year_of_admission_;
    return *this;
}

std::istream& operator>>(std::istream& in, Train& object)
{
    setlocale(LC_ALL, "russian");
    std::cout << "Enter the data\n";
    std::cout << "‘»Œ: ";
    getchar();
    std::getline(std::cin, object.full_name_);
    std::cout << "ƒÓÎÊÌÓÒÚ¸: ";
    std::getline(std::cin, object.post_);
    int check,this_year=2023;
    while (1)
    {
        std::cout << "";

        if (std::cin >> check)
        {
            if (check > 0&&check<=this_year)
            {
                object.year_of_admission_=check;
                getchar();
                break;
            }
        }
        else
        {
            std::cout << "Incorrect value\n";
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Train& object)
{
    setlocale(LC_ALL, "russian");
    out << "‘»Œ: " << object.full_name_ << std::endl;
    out << "ƒÓÎÊÌÓÒÚ¸: " << object.post_ << std::endl;
    out << "√Ó‰ ÔÓÒÚÛÔÎÂÌËˇ Ì‡ ‡·ÓÚÛ: " << object.year_of_admission_ << std::endl;
    return out;
}

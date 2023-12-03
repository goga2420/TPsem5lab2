#pragma once
#include "keeper.hpp"
std::string menu = "1-Add object\n2-Delete object\n3-Display object\n4-Change data\n5-Available trains\n6-Return to previos menu\n";
void Menu(Keeper& object)
{
    int choose, i;
    bool flag = true;
    while (flag)
    {
        std::cout << menu;
        std::cin >> choose;
        switch (choose) {
        case 1:
            object.Push();
            break;
        case 2:
            object.Show();
            object.Pop();
            break;
        case 3:
            object.Show();
            break;
        case 4:
            object.Show();
            std::cout << "Chose which element to change: ";
            std::cin >> i;
            object.Edit(i);
            break;
        case 5:
            object.TrainInfo();
            break;
        case 6:
            flag = false;
            std::cout << "Returning\n";
            break;
        default:
            std::cout << "Wrong input\n";

            break;
        }
    }
}

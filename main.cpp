#include "menu.hpp"
#include "second_task.hpp"
std::string main_menu = "1-First task\n2-Second task\n3-Exit\n";
int main()
{
    Keeper train;
    int button;
    bool flag = true;
    while (flag)
    {
        std::cout << main_menu;
        std::cin >> button;
        switch (button) {
        case 1:
            Menu(train);
            break;
        case 2:
            Task2();
            break;
        case 3:
            flag = false;
            std::cout << "Work is over\n";
            break;
        default:
            std::cout << "Wrong value\n";
            system("pause");
            break;
        }
    }
    return 0;
}

#pragma once
#include "train.hpp"
class Keeper
{
public:
    Keeper();
    ~Keeper();
    Keeper(Train* obj);
    void Sort();//
    void Push();//
    void Pop();//
    void Show();//
    void Edit(const int& change);//
    void TrainInfo();
private:
    Train* object;
    int size;
};

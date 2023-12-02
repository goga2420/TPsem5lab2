#pragma once
#include "train.hpp"
class Keeper
{
public:
    Keeper();
    ~Keeper();
    Keeper(Worker* obj);
    void Sort();//‘ÛÌÍˆËˇ ÒÓÚËÓ‚ÍË ÔÓ ‡ÎÙ‡‚ËÚÌÓÏÛ ÔÓˇ‰ÍÛ
    void Push();//‰Ó·‡‚ÎÂÌËÂ Ó·˙ÂÍÚ‡
    void Pop();//Û‰‡ÎÂÌËÂ Ó·˙ÂÍÚ‡
    void Show();//‚˚‚Ó‰ Ì‡ ˝Í‡Ì
    void Edit(const int& change);//Â‰‡ÍÚËÓ‚‡ÌËÂ Ó·˙ÂÍÚ‡
    void BestExperience(int exp);
private:
    Train* object;
    int size;
};


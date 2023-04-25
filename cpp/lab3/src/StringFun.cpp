#include <iostream>
#include <vector>
#include <algorithm>
#include "StringFun.h"

std::vector<std::function<bool(const MyString, const MyString)>> MyStringContainer::_fun = {Less(), Greater()};

void PrintNames(std::vector<MyString> names)
{
    for(int i=0; i<names.size(); i++)
    {
        std::cout << names[i].str() << " ";
    }
    std::cout << std::endl;
}
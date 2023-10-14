#pragma once
#include <iostream>
#include <string>

class Named
{
    private:
        std::string _str="None";
    public:
        friend void operator>>(const std::string str, Named & a)
        {
            a._str=str;
        }
        
        std::string Name() const {return _str;}
        void setStr(std::string str) {_str=str;}
};

//void operator>>(const std::string str, Named & a);
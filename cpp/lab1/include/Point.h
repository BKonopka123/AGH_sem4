#pragma once
#include <iostream>
#include "Named.h"

class Point : public Named
{
    private:
        double _x;
        double _y;
    public:
        friend std::ostream & operator<<(std::ostream &o,const Point & a)
        {
            return o <<  a.Name() << " ["<< a._x << "," << a._y << "]";
        }

        Point(double x=0.0, double y=0.0, std::string str="None"): _x(x), _y(y) {setStr(str);}
        ~Point() {}
        Point& operator++()
        {
            this->_x+=1;
            this->_y+=1;
            return *this;
        }
        Point operator++(int)
        {
            Point temp = *this;
            operator++();
            return temp;
        }

        double getX() const {return _x;}
        double getY() const {return _y;}
};

std::ostream & operator<<(std::ostream & o, const Point & a);
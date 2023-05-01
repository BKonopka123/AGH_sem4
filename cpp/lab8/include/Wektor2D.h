#pragma once

#include <iostream>
#include <string>
#include <initializer_list>
#include <set>
#include <algorithm>
#include <list>

class Wektor2D
{
    private:
        int _x;
        int _y;
        std::string _name;

    public:
        /**
         * @brief Construct a new Wektor 2 D object
         */
        Wektor2D(std::string name, int x, int y): _name(name), _x(x), _y(y) {}

        /**
         * @brief getters
         */
        std::string getname() const {return _name;}
        int getx() const {return _x;}
        int gety() const {return _y;}

        /**
         * @brief << operator overload
         */
        friend std::ostream& operator<<(std::ostream& out, const Wektor2D& a)
        {
            return out << a.getname() << " (" << a.getx() << "," << a.gety() << ")";
        }

        /**
         * @brief < operator overload
         */
        bool operator<(const Wektor2D& a) const
        {
            return getx() < a.getx();
        }

};
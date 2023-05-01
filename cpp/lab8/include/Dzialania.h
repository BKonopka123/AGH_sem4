#pragma once

#include <iostream>
#include <string>
#include <initializer_list>
#include <set>
#include <algorithm>
#include <list>

class DzialaniaNaZbiorach
{
    private:
        std::set<Wektor2D> _set;

    public:
        /**
         * @brief Construct a new Dzialania Na Zbiorach object
         */
        DzialaniaNaZbiorach(std::set<Wektor2D> set): _set(set) {}

        /**
         * @brief prints all emelents with x bigger than i
         */
        void WypiszXWiekszeOd(int i)
        {
            std::for_each(_set.upper_bound(Wektor2D("", i-1, 0)), _set.end(), [](const Wektor2D& a){ std::cout << a << std::endl; });
        }

        /**
         * @brief changes x value of object from i to j
         */
        void ZamienX(int i, int j)
        {
            std::set<Wektor2D>::iterator it;
            it = _set.find(Wektor2D("", i, 0));
            Wektor2D temp = *it;
            it=_set.erase(it);
            _set.insert(it, Wektor2D(temp.getname(), j, temp.gety()));
        }
};

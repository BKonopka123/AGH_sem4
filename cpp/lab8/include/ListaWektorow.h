#pragma once

#include <iostream>
#include <string>
#include <initializer_list>
#include <set>
#include <algorithm>
#include <list>

class ListaWektorow
{
    private:
        std::list<Wektor2D*> _list;

    public:
        /**
         * @brief Construct a new Lista Wektorow object
         */
        ListaWektorow() {std::cout << "Nieposortowana" << std::endl;}

        /**
         * @brief add element to list
         */
        void Dodaj(Wektor2D *a)
        {
            _list.emplace_back(a);
        }

        /**
         * @brief print list
         */
        void Wypisz() const
        {
            std::for_each(_list.begin(), _list.end(), [](const Wektor2D* a){std::cout << *a << std::endl;});
        }

        /**
         * @brief sort x 
         */
        void PosortujWedlugX()
        {
            std::cout << "Posortowana wedlug wsprzednych X" << std::endl;
            _list.sort([](const Wektor2D *a, const Wektor2D *b) {return a->getx() < b->getx();});
        }

        /**
         * @brief sort y
         */
        void PosortujWedlugY()
        {
            std::cout << "Posortowana wedlug wsprzednych Y" << std::endl;
            _list.sort([](const Wektor2D *a, const Wektor2D *b) {return a->gety() < b->gety();});
        }
};
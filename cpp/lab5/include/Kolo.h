#pragma once
#include <iostream>
#include "Ksztalt.h"

/**
 * @brief Klasa Kolo dziedziczaca po Ksztalt
 */
class Kolo : public Ksztalt
{
    private:
        double _radius;

    public:
        /**
         * @brief Konstruktor Kola
         */
        Kolo(double radius): _radius(radius) {}

        /**
         * @brief Nadpisanie wirtualnego wypisz - wypisuje Kolo
         */
        void wypisz(std::ostream &o) const override 
        {
            o << "Kolo o promieniu: " << _radius << std::endl;
        }

        /**
         * @brief Nadpisanie wirulnego pole - zwaraca pole Kola
         */
        double polePow() const override 
        {
            return _radius * _radius * 3.1415;
        }
};
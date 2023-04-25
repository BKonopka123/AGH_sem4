#pragma once
#include <iostream>
#include "Ksztalt.h"

/**
 * @brief Klasa kwadrat dzieciczaca po Ksztalt
 */
class Kwadrat : public Ksztalt
{
    private:
        double _side;

    public:
        /**
         * @brief Konstruktor Kwadratu
         */
        Kwadrat(double side): _side(side) {}

        /**
         * @brief Nadpisanie wirtualnego wypisz - wypisuje Kwadrat
         */
        void wypisz(std::ostream &o) const override 
        {
            o << "Kwadrat o boku: " << _side << std::endl;
        }

        /**
         * @brief Nadpisanie wirulnego pole - zwaraca pole kwadratu
         */
        double polePow() const override 
        {
            return _side * _side;
        }
};
#pragma once
#include <iostream>
#include <cmath>
#include "Ksztalt.h"

/**
 * @brief Klasa Trojkat dziedziczaca po Ksztalt
 */
class Trojkat : public Ksztalt
{
    private:
        double _side1;
        double _side2;
        double _side3;

    public:
        /**
         * @brief Konstruktor Trojkata
         */
        Trojkat(double side1, double side2, double side3): _side1(side1), _side2(side2), _side3(side3) {}

        /**
         * @brief adpisanie wirtualnego wypisz - wypisuje Trojkat
         */
        void wypisz(std::ostream &o) const override 
        {
            o << "Trojkat o bokach: " << _side1 << " " << _side2 << " " << _side3 << std::endl;
        }

        /**
         * @brief Nadpisanie wirulnego pole - zwaraca pole trojkata 
         */
        double polePow() const override 
        {
            double x=(_side1 + _side2 + _side3)/2.0;
            return sqrt(x*(x-_side1)*(x-_side2)*(x-_side3));
        }
};
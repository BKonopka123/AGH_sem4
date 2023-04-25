#pragma once
#include <iostream>

/**
 * @brief Klasa abstrakcyjna Ksztalt
 */
class Ksztalt
{
    public:
        /**
         * @brief Destruktor wirtualny
         */
        virtual ~Ksztalt() {}
        
        /**
         * @brief Metoda czysto wirtualna wypisz - wypisuje ksztalt i boki/promien
         */
        virtual void wypisz(std::ostream &o) const =0;

        /**
         * @brief Metoda czysto wirtualna - zwraca pole ksztaltu
         */
        virtual double polePow() const =0;
};


/**
 * @brief funkcja globalna wypisz - wywoluje wirtualne wypisz na obiekcie 
 */
void wypisz(const Ksztalt & obj)
{
    obj.wypisz(std::cout);
} 
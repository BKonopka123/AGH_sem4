#pragma once
#include <iostream>

/**
 * @brief Klasa bazowa dla operatorow dwu-argumentowych
 * 
 */
class TwoArg
{
    public:
        /**
         * @brief virtualna metoda zwracajaca wynik operacji dwu-argumentowej
         */
        virtual bool result(bool arg1, bool arg2) const =0;
};

/**
 * @brief Klasa bazowa dla operatorow jedno-argumentowych
 * 
 */
class OneArg
{
    public:
        /**
         * @brief virtualna metoda zwracajaca wynik operacji jedno-argumentowej
         */
        virtual bool result(bool arg) const=0;
};

class OR : public TwoArg
{
    public:
        /**
         * @brief override wyniku, zwraca wynik operatora OR
         */
        bool result(bool arg1, bool arg2) const override
        {
            return arg1 || arg2;
        }
};

class AND : public TwoArg
{
    public:
        /**
         * @brief override wyniku, zwraca wynik operatora AND
         */
        bool result(bool arg1, bool arg2) const override
        {
            return arg1 && arg2;
        }
};

class NOT : public OneArg
{
    public:
        /**
         * @brief override wyniku, zwraca wynik operatora NOT
         */
        bool result(bool arg) const override
        {
            return !arg;
        }
};


namespace Logical
{
    /**
     * @brief Funkcja wywolujaca polimorficznie virtualna funkcje klasy TwoArg
     */
    bool eval(const TwoArg& op, bool arg1, bool arg2)
    {
        return op.result(arg1, arg2);
    }
    /**
     * @brief Funkcja wywolujaca polimorficznie virtualna funkcje klasy OneArg
     */
    bool eval(const OneArg& op, bool arg)
    {
        return op.result(arg);
    }
}
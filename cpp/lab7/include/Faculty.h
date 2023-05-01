#pragma once
#include <iostream>
#include "Person.h"

class Person;

class Faculty : virtual public Person
{
    private:
        std::string _spec;

    public:
        /**
         * @brief Construct a new Faculty object
         */
        Faculty(const char* name, const char* spec): Person(name), _spec(spec) {}

        /**
         * @brief Destroy the Faculty object
         */
        ~Faculty() {std::cout << "~Faculty (" << Person::getname() << ", spec=" << _spec << ")" << std::endl;}

        /**
         * @brief spec getter
         */
        std::string getspec() const {return _spec;}

        /**
         * @brief overloaded print
         */
        std::string print() const override 
        {
            std::string temp = "Faculty: ";
            temp += Person::print();
            temp += " spec: ";
            temp += _spec;
            return temp; 
        }
};
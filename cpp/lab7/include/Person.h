#pragma once
#include <iostream>

class Person
{
    private:
        std::string _name;

    public:
        /**
         * @brief Construct a new Person object
         */
        Person(const char *name): _name(name) {}

        /**
         * @brief Destroy the Person object
         */
        virtual ~Person() {std::cout << "~Person (" << _name << ")" << std::endl;}

        /**
         * @brief name getter 
         */
        std::string getname() const {return _name;}

        /**
         * @brief virtual print
         */
        virtual std::string print() const
        {
            std::string temp = "Person: name: ";
            temp += _name;
            return temp;
        }

        /**
         * @brief << operator overload
         */
        friend std::ostream& operator<<(std::ostream& out, const Person& a)
        {
            return out << a.print();
        }
};
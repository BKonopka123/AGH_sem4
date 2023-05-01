#pragma once
#include <iostream>
#include "Person.h"

class Person;

class Student : virtual public Person
{
    private:
        int _id;
        
    public:
        /**
         * @brief Construct a new Student object
         */
        Student(const char* name, int id): Person(name), _id(id) {}

        /**
         * @brief Destroy the Student object
         */
        ~Student() {std::cout << "~Student (" << Person::getname() << ", id=" << _id << ")" << std::endl;}

        /**
         * @brief id getter
         */
        int getid() const {return _id;}

        /**
         * @brief overloaded print
         */
        std::string print() const override 
        {
            std::string temp = "Student: ";
            temp += Person::print();
            temp += " id: ";
            temp += std::to_string(_id);
            return temp; 
        }
};
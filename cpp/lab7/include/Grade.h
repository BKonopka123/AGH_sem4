#pragma once
#include <iostream>
#include "Student.h"
#include "Faculty.h"

class Person;
class Student;
class Faculty;

class Grade : public Student, public Faculty
{
    public:
        /**
         * @brief Construct a new Grade object
         */
        Grade(const char* name, int id, const char* spec): Person(name), Student(name, id), Faculty(name, spec) {}

        /**
         * @brief Destroy the Grade object
         */
        ~Grade() {std::cout << "~Grade (" << Person::getname() << ", id=" << Student::getid() << ", spec=" << Faculty::getspec() << ")" << std::endl;}

        /**
         * @brief overloaded print
         */
        std::string print() const override
        {
            std::string temp = "jako: ";
            temp += Person::print();
            temp += "\njako: ";
            temp += Student::print();
            temp += "\njako: ";
            temp += Faculty::print();
            return temp;
        }
};
#pragma once
#include <iostream>
#include "Data.h"

class Data;
class IntData;
class StringData;

class List
{
    private:
        Data* _head = nullptr;

    public:
        /**
         * @brief Konstruktor Listy
         */
        List() {}

        /**
         * @brief Destruktor listy
         */
        ~List() 
        {
            if(_head)
            {
                while(_head->getNext())
                {
                    Data *temp = _head;
                    while(temp->getNext()->getNext()) 
                        temp = temp->getNext();
                    delete(temp->getNext());
                    temp->setNext(nullptr);
                }
                delete(_head);
            }
        }

        /**
         * @brief Konstruktor kopiujący Listy
         */
        List(const List & a) 
        {
            Data *temp = a._head;
            while(temp)
            {
                temp->addelem(*this);
                temp = temp->getNext();
            }  
        }

        enum _moment{Begin, End};

        /**
         * @brief Wstawianie do listy obiektu typu IntData
         */
        List & insert(const IntData &a, const List::_moment b = List::End); 

        /**
         * @brief Wstawianie do listy obiektu typu StringData
         */
        List & insert(const StringData &a, const List::_moment b = List::End);

        List & insert(const FloatData &a, const List::_moment b = List::End);

        /**
         * @brief Wypisywanie listy
         */
        void print() const;

        /**
         * @brief Metoda szukajaca elementu w lisice
         */
        bool find(const Data& a) const;

        /**
         * @brief Konkatenacja list
         */
        List & operator<<(List& b);
};

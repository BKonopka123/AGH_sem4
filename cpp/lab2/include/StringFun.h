#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class MyString
{
    private:
        std::string _str;

    public:
        /**
         * @brief Konstryktor MyString
         * 
         * @param str const char *
         */
        MyString(const char * str): _str(str) {}
        
        /**
         * @brief Destruktor MyString
         * 
         */
        ~MyString() {}

        /**
         * @brief Funkcja zwracajca string z MyStringa
         * 
         * @return std::string zwracany string
         */
        std::string str() const {return _str;}

        /**
         * @brief operator przyrownania <=
         * 
         * @param b 
         * @return true 
         * @return false 
         */
        bool operator<=(const MyString b) const
        {
            return this->_str <= b.str() ? 1 : 0;
        }

        /**
         * @brief operator przyrownania >
         * 
         * @param b 
         * @return true 
         * @return false 
         */
        bool operator>(const MyString b) const
        {
            return this->_str > b.str() ? 1 : 0;
        }
};

/**
 * @brief Funkcja wypisujaca wektor names
 * 
 * @param names wektor do wypsiania
 */
void PrintNames(std::vector<MyString> names);

/**
 * @brief Funktor Less
 * 
 */
class Less
{
    public:
        bool operator()(const MyString a, const MyString b) const {return a <= b ? 1 : 0;}
};

/**
 * @brief Funktor Greater
 * 
 */
class Greater
{
    public:
        bool operator()(const MyString a, const MyString b) const {return a > b ? 1 : 0;}
};

/**
 * @brief Funktor Lenght
 * 
 */
class Length
{
    public:
        bool operator()(const MyString a, const MyString b) const {return a.str().length() < b.str().length() ? 1 : 0;}
};
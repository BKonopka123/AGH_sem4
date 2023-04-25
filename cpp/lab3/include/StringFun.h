#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

class MyString
{
    private:
        std::string _str;

    public:
        /**
         * @brief Konstruktor klasy  MyString
         * 
         * @param str 
         */
        MyString(const char * str): _str(str) {}

        /**
         * @brief Konstruktor konwertujcy MyString* na Mystring
         * 
         * @param a 
         */
        MyString(MyString *a): _str(a->str()) {}
        
        /**
         * @brief Defaultowy destruktor MyString
         * 
         */
        ~MyString() {}

        /**
         * @brief Get string
         * 
         * @return std::string 
         */
        std::string str() const {return _str;}

        /**
         * @brief operator <=
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
         * @brief operator >
         * 
         * @param b 
         * @return true 
         * @return false 
         */
        bool operator>(const MyString b) const
        {
            return this->_str > b.str() ? 1 : 0;
        }

        /**
         * @brief operator new
         * 
         * @param size 
         * @return void* 
         */
        void* operator new(size_t size)
        {
            std::cout << "[MyString] Overloading new operator with size: " << size << std::endl;
            void* tmp = malloc(size);

            return tmp;
        }

        /**
         * @brief operator delete
         * 
         * @param tmp 
         */
        void operator delete(void * tmp)
        {
            std::cout << "[MyString] Overloading delete operator \n";
            free(tmp);
        }

};

/**
 * @brief Funktor porownujacy mystringi i zwracajacy mniejszy z nich
 * 
 */
class Less
{
    public:
        bool operator()(const MyString a, const MyString b) const {return a <= b ? 1 : 0;}
};

/**
 * @brief funktor porownujacy mystringi i zwracajacy wiekszy z nich
 * 
 */
class Greater
{
    public:
        bool operator()(const MyString a, const MyString b) const {return a > b ? 1 : 0;}
};

class MyStringContainer
{
    private:
        std::vector<MyString*> _ptr;
        static std::vector<std::function<bool(const MyString, const MyString)>> _fun;
    
    public:
        /**
         * @brief Defaultowy konstruktor
         * 
         */
        MyStringContainer() {}

        /**
         * @brief Destruktor zwalniajacy wskazniki mystring
         * 
         */
        ~MyStringContainer()
        {
            for(auto x : _ptr)
            {
                delete x;
            }
        }

        /**
         * @brief Konstruktor kopiujacy
         * 
         * @param a 
         */
        MyStringContainer(const MyStringContainer& a)
        {
            for(int i=0; i<a._ptr.size(); i++)
            {
                auto tmp = new MyString(a._ptr[i]);
                _ptr.push_back(tmp);
            }
        }

        /**
         * @brief dodawanie Mystring* do wektora _ptr
         * 
         * @param a 
         */
        void AddMStr(MyString* a)
        {
            _ptr.push_back(a);
        }

        /**
         * @brief Sortowanie wekora _ptr
         * 
         * @param str 
         * @return std::vector<MyString> 
         */
        std::vector<MyString> GetSorted(std::string str)
        {
            std::vector<MyString> wtr(_ptr.begin(), _ptr.end());
            if(str=="ASC")
                std::sort(wtr.begin(), wtr.end(), _fun[0]);
            else
                std::sort(wtr.begin(), wtr.end(), _fun[1]);
            return wtr;
        }

        /**
         * @brief funkcja zwracajaca wektor funktorow
         * 
         * @return std::vector<std::function<bool(const MyString, const MyString)>> 
         */
        static std::vector<std::function<bool(const MyString, const MyString)>> SortFunc()
        {
            return _fun;
        }


};

/**
 * @brief wypisywanie wektora
 * 
 * @param names 
 */
void PrintNames(std::vector<MyString> names);
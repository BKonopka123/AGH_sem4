#pragma once
#include <iostream>

class List;

class Data
{
    public:
       
        /**
         * @brief Wirtualny destruktor
         */
        virtual ~Data() {}

        /**
         * @brief Wirtualna metoda wypisująca obiekt
         */
        virtual void print(std::ostream& out) const = 0;

        /**
         * @brief Wirtualna metoda ustwiajaca wskaznik na nastepny obiekt w lisice
         */
        virtual void setNext(Data *a) =0;

        /**
         * @brief Wirtualna metoda pobierajaca wskaznik na nastepny element w liscie
         * 
         * @return Data* 
         */
        virtual Data * getNext() const =0;

        /**
         * @brief Wirtualna metoda kopiujaca obiekt podczas kopiowania listy
         */
        virtual void addelem(List &a) const =0;

        /**
         * @brief wirtualna metoda sprawdzajaca czy elementy sa takie same
         */
        virtual bool isSame(const Data& a) const =0;
};

class IntData : public Data
{
    private:
        int _data;
        Data * _next;

    public:
        
        /**
         * @brief Konstruktor IntData
         */
        IntData(int a, Data *b = nullptr): _data(a), _next(b) {}

        /**
         * @brief Destruktor IntData
        */
        ~IntData() 
        {
            //std::cout << "~IntData()" << std::endl;
        }

        /**
         * @brief Wypisywanie obiektu IntData
         */
        void print(std::ostream& out) const override 
        {
            out << _data << ", ";
            if(_next)
                _next->print(out);
        }
        
        /**
         * @brief Ustawianie wskaznika na nastepny element w liscie
         */
        void setNext(Data *a) override {_next = a;}

        /**
         * @brief Pobieranie wskaznika na nastepny element w lisice
         */
        Data * getNext() const override {return _next;}

        /**
         * @brief Pobieranie wartosci obiektu intdata
         */
        int getValue() const {return _data;}

        /**
         * @brief Kopiowanie elementu intdata do innej listy 
         */
        void addelem(List &a) const override;

        /**
         * @brief Metoda sprawdzajaca czy elementy sa takie same
         */
        bool isSame(const Data& a) const override
        {
            try 
            {
                auto converted =  dynamic_cast<const IntData&>(a);
                if(converted.getValue() == _data)
                    return true;
                else
                    return false;
            } 
            catch(std::bad_cast) {
                return false; 
            }
        }

};

class StringData : public Data
{
    private:
        std::string _data;
        Data * _next;

    public:
        
        /**
         * @brief Konstruktor StringData
         */
        StringData(std::string a, Data *b = nullptr): _data(a), _next(b) {}
        
        /**
         * @brief Destruktor StringData
         */
        ~StringData() 
        {
            //std::cout << "~StringData()" << std::endl;
        }

        /**
         * @brief Wypisywanie obiektu StringData
         */
        void print(std::ostream& out) const override 
        {
            out <<"\"" << _data << "\", ";
            if(_next)
                _next->print(out);
        }

        /**
         * @brief Ustawianie wskaznika na nastepny elemnt w liscie
         */
        void setNext(Data *a) override {_next = a;}
        
        /**
         * @brief Pobieranie wskaznika na kolejny elemnt w liscie
         */
        Data * getNext() const override {return _next;}

        /**
         * @brief pobranie wartosci stringdata
         */
        std::string getValue() const {return _data;}

        /**
         * @brief Kopiowanie elementu StringData do nowej listy
         */
        void addelem(List &a) const override;

        /**
         * @brief Metoda sprawdzajaca czy elementy sa takie same
         */
        bool isSame(const Data& a) const override
        {
            try 
            {
                auto converted =  dynamic_cast<const StringData&>(a);
                if(converted.getValue() == _data)
                    return true;
                else
                    return false;
            } 
            catch(std::bad_cast) {
                return false; 
            }
        }
};

class FloatData : public Data
{
    private:
        float _data;
        Data * _next;

    public:
        
        /**
         * @brief Konstruktor FloatData
         */
        FloatData(float a, Data *b = nullptr): _data(a), _next(b) {}

        /**
         * @brief Destruktor FloatData
        */
        ~FloatData() 
        {
            //std::cout << "~FloatData()" << std::endl;
        }

        /**
         * @brief Wypisywanie obiektu FloatData
         */
        void print(std::ostream& out) const override 
        {
            out << _data << ", ";
            if(_next)
                _next->print(out);
        }
        
        /**
         * @brief Ustawianie wskaznika na nastepny element w liscie
         */
        void setNext(Data *a) override {_next = a;}

        /**
         * @brief Pobieranie wskaznika na nastepny element w lisice
         */
        Data * getNext() const override {return _next;}

        /**
         * @brief Pobieranie wartosci obiektu intdata
         */
        float getValue() const {return _data;}

        /**
         * @brief Kopiowanie elementu intdata do innej listy 
         */
        void addelem(List &a) const override;

        /**
         * @brief Metoda sprawdzajaca czy elementy sa takie same
         */
        bool isSame(const Data& a) const override
        {
            try 
            {
                auto converted =  dynamic_cast<const FloatData&>(a);
                if(converted.getValue() == _data)
                    return true;
                else
                    return false;
            } 
            catch(std::bad_cast) {
                return false; 
            }
        }

};
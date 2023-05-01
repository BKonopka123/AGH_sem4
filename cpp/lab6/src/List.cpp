#include "List.h"

List & List::insert(const IntData &a, const List::_moment b) 
{
    if(b == List::Begin)
    {
        Data * new_data = new IntData(a.getValue(), _head);
        _head = new_data;
        return *this;
    }
    else
    {
        Data *temp = _head;
        if(temp == nullptr)
        {
            Data * new_data = new IntData(a.getValue());
            _head = new_data;
            return *this;
        }
        while(temp->getNext()) 
            temp = temp->getNext();
        Data * new_data = new IntData(a.getValue());
        temp->setNext(new_data);
        return *this;
    }
}

List & List::insert(const StringData &a, const List::_moment b) 
{
    if(b == List::Begin)
    {
        Data * new_data = new StringData(a.getValue(), _head);
        _head = new_data;
        return *this;
    }
    else
    {
        Data *temp = _head;
        if(temp == nullptr)
        {
            Data * new_data = new StringData(a.getValue());
            _head = new_data;
            return *this;
        }
        while(temp->getNext()) 
            temp = temp->getNext();
        Data * new_data = new StringData(a.getValue());
        temp->setNext(new_data);
        return *this;
    }
}

List & List::insert(const FloatData &a, const List::_moment b)
{
    if(b == List::Begin)
    {
        Data * new_data = new FloatData(a.getValue(), _head);
        _head = new_data;
        return *this;
    }
    else
    {
        Data *temp = _head;
        if(temp == nullptr)
        {
            Data * new_data = new FloatData(a.getValue());
            _head = new_data;
            return *this;
        }
        while(temp->getNext()) 
            temp = temp->getNext();
        Data * new_data = new FloatData(a.getValue());
        temp->setNext(new_data);
        return *this;
    }
}

void List::print() const
{
    if(_head)
    {
        std::cout << "[";
        _head->print(std::cout);
        std::cout << "\b\b]" << std::endl;
    }
    else
    {
        std::cout << "[]" << std::endl;
    }
}

bool List::find(const Data& a) const
{
    Data * temp = _head;
    while(temp)
    {
        if(temp->isSame(a))
            return true;
        temp = temp->getNext();
    }
    return false;
}

List & List::operator<<(List& b)
{
    Data* temp = _head;
    if(temp)
    {
        while(temp->getNext())
            temp=temp->getNext();
    
        temp->setNext(b._head);
        b._head = nullptr;
    }
    else
    {
        temp = b._head;
    }
    return *this;
}
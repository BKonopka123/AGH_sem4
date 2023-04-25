#pragma once
#include <iostream>
#include "Named.h"
#include "Point.h"

class PointSmartPtr
{
    private:
        Point * _pp;
        static int * _pi;
    public:
        PointSmartPtr(Point * a): _pp(a) {(*_pi)++;}
        
        PointSmartPtr(const PointSmartPtr &a)
        {
            Point *temp = new Point(a._pp->getX(), a._pp->getY(), a._pp->Name());
            _pp = temp;
            (*_pi)++;
        }
        
        ~PointSmartPtr() 
        {
            release();
        }

        Point& operator*()
        {
            return *_pp;
        }
        
        PointSmartPtr& operator=(const PointSmartPtr& a)
        {
            Point *temp = new Point(a._pp->getX(), a._pp->getY(), a._pp->Name());
            (*_pi)++;
            release();
            _pp = temp;
            return *this;
        }

        void release()
        {
            (*_pi)--;
            delete _pp;
        }
};
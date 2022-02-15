#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

#include <iostream>
using namespace std;

template <class T>
class CompareBehaviour
{
    public:
        /*
            Function:   compare
            Purpose:    compare 2 values and return if first value is greater than second value 
            in:         type T
            in:         type T
        */
        virtual bool compare(T, T)=0;
};

#endif
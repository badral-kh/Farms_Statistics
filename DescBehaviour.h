#ifndef DESCBEHAVIOUR_H
#define DESCBEHAVIOUR_H

#include "CompareBehaviour.h"
using namespace std;

template <class T>
class DescBehaviour: public CompareBehaviour<T>
{
    public:
        /*
            Function:   compare
            Purpose:    compare 2 values and return if first value is greater than second value 
            in:         type T
            in:         type T
        */
        virtual bool compare(T, T);
};

template <class T>
bool DescBehaviour<T>::compare(T t1, T t2)
{
    return (t1 > t2);
}

#endif
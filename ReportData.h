#ifndef REPORTDATA_H
#define REPORTDATA_H

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include "CompareBehaviour.h"
using namespace std;

template <class T>
class ReportData
{   
    template <class A>
    friend ostream& operator<<(ostream&, const ReportData<A>&);

    template<class X>
    class ReportRow
    {
        public:
            ReportRow(X k,string data) 
                : key(k), rowData(data)
            {}

            X key;
            string rowData;
    };

    public:
        ReportData(CompareBehaviour<T>* = NULL); 
        ~ReportData();
        /*
            Function:   add
            Purpose:    add the data to the row with ascending order of T type
            in:         key of T type
            in:         data
        */
        void add(T, string);
        /*
            Function:   clean
            Purpose:    clean the report rows
        */
        void clean();

    private:
        vector<ReportRow <T> > rows;
        CompareBehaviour<T>* behaviour;

};


template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* cb)
    : behaviour(cb)
{}

template <class T>
ReportData<T>::~ReportData()
{
    delete behaviour;
}

template <class T>
void ReportData<T>::clean()
{
    rows.clear();
}

template <class T>
ostream& operator<<(ostream& output, const ReportData<T>& rd)
{   
    for (int i=0; i<rd.rows.size(); ++i){
        output << rd.rows[i].rowData << endl;
    }

    return output;
}

template <class T>
void ReportData<T>::add(T key, string row)
{
    ReportRow<T> rRow(key,row);
    typename vector<ReportRow <T> >::iterator itr;
    for (itr = rows.begin(); itr != rows.end(); ++itr){
        if(behaviour->compare(key, itr->key)) {
            rows.insert(itr,rRow);
            return;
        }
    }
    rows.insert(itr,rRow);
    return;
}
#endif

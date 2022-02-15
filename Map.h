#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


template <class T>
class Map
{
    public:
        /*
            Function:   add
            Purpose:    add key and value Record pointer to a map 
            in:         type T
            in:         Record pointer
        */
        void add(T key, Record* rec);
        /*
            Function:   getKeySize
            Purpose:    return key size
        */
        int getKeySize() const;
        /*
            Function:   getKeys
            Purpose:    return keys of a map
        */
        vector<T>& getKeys();
        vector<Record*>& operator[](T);

    private:
        vector<T> keys;  
        vector<vector<Record*> > values;
};

//Start of implementation

template <class T>
void Map<T>::add(T key, Record* rec)
{
    for(int i=0; i<keys.size(); ++i){
        if (keys[i] == key){
            values[i].push_back(rec);
            return;
        }
    }
    keys.push_back(key);
    vector<Record*> vec;
    vec.push_back(rec);
    values.push_back(vec);
    return;
}

template <class T>
int Map<T>::getKeySize() const { return keys.size(); }

template <class T>
vector<T>&  Map<T>::getKeys() { return keys; }

template <class T>
vector<Record*>& Map<T>::operator[](T key)
{
    for (int i=0; i<keys.size(); ++i){
        if (keys[i] == key){
            return values.at(i);
        }
    }
    throw "not found bro";
}

#endif
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Record
{
    public:

        Record(int = 0, string = "Unknown", string = "Unknown", string = "Unknown", int = 0, int = 0);
        ~Record();
        int getYear() const;
        string getRegion() const;
        string getSubRegion() const;
        string getAnimalType() const;
        int getNumFarms() const;
        int getNumAnimals() const;

    private:
        int year;
        string region;
        string subRegion;
        string animalType;
        int numFarms;
        int numAnimals;
    };

#endif

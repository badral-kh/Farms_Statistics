#include "Record.h"

Record::Record(int y, string r, string sr, string at, int nf, int na)
    : year(y) , region(r), subRegion(sr), animalType(at), numFarms(nf), numAnimals(na)
{}

Record::~Record()
{}

int Record::getYear() const { return year;}
string Record::getRegion() const { return region;}
string Record::getSubRegion() const { return subRegion;}
string Record::getAnimalType() const { return animalType;}
int Record::getNumFarms() const { return numFarms;}
int Record::getNumAnimals() const { return numAnimals;}



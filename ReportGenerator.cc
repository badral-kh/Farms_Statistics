#include "ReportGenerator.h"

vector<Record*> ReportGenerator::records;
Map<string> ReportGenerator::regionMap;
Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::animalMap;

ReportGenerator::ReportGenerator()
{}

ReportGenerator::~ReportGenerator()
{}

void ReportGenerator::cleanup(){
    for (int i=0; i<records.size(); ++i){
        delete records[i];
    }
}

void ReportGenerator::populateRecords(){

    int iYear, iNumFarms, iNumAnimals;
    string iRegion, iSubRegion, iAnimalType;

    ifstream infile("farms.dat", ios::in);

    if (!infile){
        cout << "Error: could not open file" << endl;
        exit(1);
    }

    while ( infile >> iYear >> iRegion >> iSubRegion >> iAnimalType >> iNumFarms >> iNumAnimals) {
        records.push_back(new Record(iYear, iRegion, iSubRegion, iAnimalType, iNumFarms, iNumAnimals));
    }
    return;
}

void ReportGenerator::populateMaps(){
    for (int i=0; i<records.size(); ++i){
        animalMap.add(records[i]->getAnimalType(), records[i]);
        regionMap.add(records[i]->getRegion(), records[i]);
        yearMap.add(records[i]->getYear(), records[i]);
    }
}






#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "ReportData.h"
#include "Record.h"
#include "Map.h"
#include "CompareBehaviour.h"
#include "DescBehaviour.h"
#include "AscBehaviour.h"

using namespace std;

class ReportGenerator
{
    public:
        ReportGenerator();
        virtual ~ReportGenerator();
        
        /*
            Function:   populateRecords
            Purpose:    populate the records from the data file
        */
        static void populateRecords();

        /*
            Function:   populateMaps
            Purpose:    populate all the maps
        */
        static void populateMaps();

        virtual void compute() = 0;

        /*
            Function:   cleanup
            Purpose:    deallocate the Records
        */
        static void cleanup();

    protected:
        static vector<Record*> records;
        static Map<string> regionMap;
        static Map<int> yearMap;
        static Map<string> animalMap;
};

#endif

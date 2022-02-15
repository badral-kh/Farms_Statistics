#ifndef ANIMALTYPEREPORT_H
#define ANIMALTYPEREPORT_H

#include "ReportGenerator.h"
#include "CompareBehaviour.h"
using namespace std;

class AnimalTypeReport : public ReportGenerator
{
    public:
        AnimalTypeReport();
        ~AnimalTypeReport();

        /*
            Function:   compute
            Purpose:    compute and print the report
        */
        virtual void compute();

    private:
        ReportData<float>* reportData;

        /*
            Function:   formatData
            Purpose:    format the given data and add it to report data row
            in:         reference to 2D vector of floats 
            in:         reference to vector of animals types
        */
        void formatData(vector<vector< int> >&, vector<string>&);

        /*
            Function:   printReport
            Purpose:    print the report to the screen and save it to a file
        */
        void printReport();
};
#endif
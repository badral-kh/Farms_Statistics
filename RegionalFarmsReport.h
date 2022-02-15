#ifndef REGIONALFARMSREPORT_H
#define REGIONALFARMSREPORT_H

#include "ReportGenerator.h"
#include "CompareBehaviour.h"

#define WIDTH 12 
using namespace std;

class RegionalFarmsReport : public ReportGenerator
{
    public:
        RegionalFarmsReport();
        ~RegionalFarmsReport();

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
            in:         reference to vector of floats 
            in:         region
        */
        void formatData(vector<float>&, string);

        /*
            Function:   printReport
            Purpose:    print the report to the screen and save it to a file
        */
        void printReport();
};
#endif
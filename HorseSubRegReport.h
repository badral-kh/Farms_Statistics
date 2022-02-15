#ifndef HORSESUBREGREPORT_H
#define HORSESUBREGREPORT_H

#include "ReportGenerator.h"
#include "CompareBehaviour.h"
using namespace std;

class HorseSubRegReport : public ReportGenerator
{
    public:
        HorseSubRegReport();
        ~HorseSubRegReport();

        /*
            Function:   compute
            Purpose:    compute and print the report
        */
        virtual void compute();

    private:
        ReportData<int>* reportData;

        /*
            Function:   formatData
            Purpose:    format the given data and add it to report data row
            in:         int: number of horses 
            in:         string: region
            in:         string: sub region
        */
        void formatData(int, string, string);

        /*
            Function:   printReport
            Purpose:    print the report to the screen and save it to a file
        */
        void printReport();
};
#endif
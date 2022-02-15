#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <vector>

#include "View.h"
#include "ReportGenerator.h"
#include "RegionalFarmsReport.h"
#include "AnimalTypeReport.h"
#include "HorseSubRegReport.h"

#include "AscBehaviour.h"
#include "DescBehaviour.h"
#include "CompareBehaviour.h"

using namespace std;

class Control
{
    public:
        /*
            Function:   Control
            Purpose:    constructor of an Control object
        */
        Control();
        /*
            Function:   ~Control
            Purpose:    desttructor of an Control object
        */
        ~Control();
        /*
            Function:   launch
            Purpose:    launch the program
        */
        void launch();
        
    private:
        View* view;
        vector<ReportGenerator*> reports;
};

#endif







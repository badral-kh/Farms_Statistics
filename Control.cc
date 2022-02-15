#include "Control.h"

Control::Control()
{
    ReportGenerator* report1 = new RegionalFarmsReport();
    ReportGenerator* report2 = new AnimalTypeReport();
    ReportGenerator* report3 = new HorseSubRegReport();

    reports.push_back(report1);
    reports.push_back(report2);
    reports.push_back(report3);
}

Control::~Control()
{
    for (int i=0; i<reports.size(); ++i){
        delete reports[i];
    }
}

void Control::launch()
{
    ReportGenerator::populateRecords();
    ReportGenerator::populateMaps();

    int choice;
    view->showMenu(choice);

    while (choice != 0){
        if (choice == 1){

            reports.at(0)->compute();
            view->showMenu(choice);

        } else if (choice == 2){

            reports.at(1)->compute();
            view->showMenu(choice);

        } else if (choice == 3){
        
            reports.at(2)->compute();
            view->showMenu(choice);
        
        } else {
            view->showMenu(choice);
        }
    }
    ReportGenerator::cleanup();
    return;
}
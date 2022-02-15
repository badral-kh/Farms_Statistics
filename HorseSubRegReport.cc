#include "HorseSubRegReport.h"

HorseSubRegReport::HorseSubRegReport()
{
    DescBehaviour<int>* descBehaveInt  = new DescBehaviour<int>();
    reportData = new ReportData<int>(descBehaveInt);
}

HorseSubRegReport::~HorseSubRegReport()
{
    delete reportData;
}

void HorseSubRegReport::compute()
{
    vector<Record*> horseVec;

    try {
        horseVec = animalMap["Horses-Ponies"];
    } catch (char * error){
        cout << error;
        return;
    }
    
    for (int i=0; i<regionMap.getKeySize(); ++i){
        string region = regionMap.getKeys()[i];

        if (region != "CAN"){

            int maxSubRegionCount = 0;
            string maxSubRegName;

            for (int k=0; k<horseVec.size(); ++k){

                Record* r = horseVec[k];

                if ((r->getSubRegion() != "All") && (r->getYear() == 2016) && (r->getNumAnimals() > maxSubRegionCount) && r->getRegion() == region){
                    maxSubRegionCount = r->getNumAnimals();
                    maxSubRegName = r->getSubRegion();
                }
            }
            formatData(maxSubRegionCount, region, maxSubRegName);
        }
    }
    printReport();
    reportData->clean();
}

void HorseSubRegReport::formatData(int numHorses, string region, string subRegion)
{
    stringstream ss;
    ss << setw(10) << right << region 
       << "      "
       << setw(35) << left << subRegion
       << setw(6) << right << numHorses;

    reportData->add(numHorses,ss.str());
    return;
}
void HorseSubRegReport::printReport()
{
    stringstream ss;
    ss << endl
       << setw(8) << " " << "SUB-REGION WITH MOST HORSES/PONIES BY REGION 2016" << endl
       << setw(8) << " " << "-------------------------------------------------" << endl << endl;

    ss << *reportData;
    cout << ss.str();

    ofstream outfile("HorseSubRegReport.txt", ios::out);

    if (!outfile){
        cout << "Error: could not open file" << endl;
        return;
    } 

    outfile << ss.str();
    return;
}





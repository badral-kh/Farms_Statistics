#include "RegionalFarmsReport.h"

RegionalFarmsReport::RegionalFarmsReport()
{
    DescBehaviour<float>* descBehaveInt = new DescBehaviour<float>();
    reportData = new ReportData<float>(descBehaveInt);
}

RegionalFarmsReport::~RegionalFarmsReport()
{
    delete reportData;
}

void RegionalFarmsReport::compute()
{
    vector<string> animalTypes = animalMap.getKeys();
    vector<int> farmCountVec;

    int grandTotal = 0;
    for (int i=0; i<animalMap.getKeySize(); ++i){

        string animal = animalTypes[i];
        int count = 0;

        vector<Record*> animalVec;
        
        try {
            animalVec = animalMap[animal];
        } catch (char * error){
            cout << error;
            return;
        }

        for (int k=0; k<animalVec.size(); ++k){

            Record* r = animalVec[k];
            
            if ((r->getYear() == 2016) && (r->getRegion() != "CAN") && (r->getSubRegion() == "All")){
                count += r->getNumFarms();
            }
        }

        farmCountVec.push_back(count);
        grandTotal += count;
    }
    farmCountVec.push_back(grandTotal);

    for (int i=0; i<regionMap.getKeySize(); ++i){

        vector<int> farmPerRegion;

        string region = regionMap.getKeys()[i];

        if (region != "CAN"){

            int regionTotal = 0;

            for (int n=0; n<animalTypes.size(); ++n){

                int count = 0;

                string animal = animalTypes[n];

                vector<Record*> regionRecords;

                try {
                    regionRecords = regionMap[region];
                } catch (char * error){
                    cout << error;
                    return;
                }

                for (int k=0; k<regionRecords.size(); ++k){

                    Record* r = regionRecords[k];
                    
                    if ((r->getYear() == 2016) && (r->getRegion() == region) && (r->getSubRegion() == "All") && (r->getAnimalType() == animal)){
                        count += r->getNumFarms();
                    }
                }
                regionTotal += count;
                farmPerRegion.push_back(count);
            }

            farmPerRegion.push_back(regionTotal);

            vector<float> ratioPerRegion;

            for (int x=0; x < farmPerRegion.size(); ++x){
                if (farmPerRegion[x] == 0){
                    ratioPerRegion.push_back(0);
                } else{
                    ratioPerRegion.push_back(100 * (float(farmPerRegion[x])/float(farmCountVec[x])));
                }
            }
            formatData(ratioPerRegion, region);
        }
    }
    printReport();
    reportData->clean();
}

void RegionalFarmsReport::formatData(vector<float>& vec, string region)
{
    stringstream ss;
    ss << region;

    for (int i=0; i<vec.size(); ++i){
        ss << setw(WIDTH) << right << fixed << setprecision(1) << vec[i];
    }

    reportData->add(vec[vec.size()-1],ss.str());
    return;
}
void RegionalFarmsReport::printReport()
{
    stringstream ss;
    stringstream body;
    stringstream topHeader;
    stringstream bottomHeader;

    vector<string> animalHeader = animalMap.getKeys();
    size_t position;

    topHeader << endl
              << setw(28) << " " << "PERCENTAGE OF FARMS BY REGION IN 2016" << endl
              << setw(28) << " " << "-------------------------------------" << endl << endl;

    topHeader << setw(3) << " " ;
    bottomHeader << setw(3) << " " ;
    for (int i=0; i<animalHeader.size(); ++i){
        string animal = animalHeader[i];
        position = animal.find("-");
        if (position > animal.length()){
            topHeader << setw(WIDTH) << right << animal;
            bottomHeader << setw(WIDTH) << " ";
        } else {
            topHeader<< setw(WIDTH-1) << right << animal.substr(0,position) << "/";
            bottomHeader << setw(WIDTH) << right << animal.substr(position + 1, animal.length());
        }
    }
    topHeader << setw(WIDTH) << right << "Totals" << endl;
    bottomHeader << endl;
    body << *reportData;

    ss << topHeader.str() << bottomHeader.str() << body.str();

    cout << ss.str();

    ofstream outfile("RegionalFarmsReport.txt", ios::out);

    if (!outfile){
        cout << "Error: could not open file" << endl;
        return;
    } 

    outfile << ss.str();
    return;
}
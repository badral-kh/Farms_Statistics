#include "AnimalTypeReport.h"

AnimalTypeReport::AnimalTypeReport()
{
    AscBehaviour<float>* ascBehaveFloat = new AscBehaviour<float>();
    reportData = new ReportData<float>(ascBehaveFloat);
}

AnimalTypeReport::~AnimalTypeReport()
{
    delete reportData;
}

void AnimalTypeReport::compute()
{
    vector<vector<int> > arr;

    vector<string> animalTypes;

    for (int i=0; i<animalMap.getKeySize(); i++){
        animalTypes.push_back(animalMap.getKeys()[i]);
    }

    vector<int> totalAnimalsPerYearVec;

    int total2011 = 0;
    int total2016 = 0;

    for (int i=0; i<yearMap.getKeySize(); ++i){

        int year = yearMap.getKeys()[i];
        vector<Record*> yearVec;

        try {
            yearVec = yearMap[year];
        } catch (char * error){
            cout << error;
            return;
        }

        int totalAnimalsPerYear = 0;

        vector<int> yearArr;
        
        for (int x=0; x<animalTypes.size(); ++x){

            string animalType = animalTypes[x];

            bool animalFound = false;

                for (int k=0; k<yearVec.size(); ++k){

                Record* r = yearVec[k];

                if (r->getAnimalType() == animalType && r->getRegion() == "CAN"){
                    yearArr.push_back(r->getNumAnimals());
                    totalAnimalsPerYear += r->getNumAnimals();
                    animalFound = true;
                }
            }
            if (animalFound == false){
                yearArr.push_back(0);
            }
        }
        totalAnimalsPerYearVec.push_back(totalAnimalsPerYear);
        arr.push_back(yearArr);
    }

    formatData(arr, animalTypes);

    printReport();
    reportData->clean();
}

void AnimalTypeReport::formatData(vector<vector< int> >& arr, vector<string>& animalTypes)
{
    int total2011 = 0;
    int total2016 = 0;
    for (int i=0; i<yearMap.getKeys().size(); ++i){
        if (yearMap.getKeys()[i] == 2011){
            for (int k=0; k<arr[i].size(); ++k){
                total2011 += arr[i][k];
            }
        }
        if (yearMap.getKeys()[i] == 2016){
            for (int k=0; k<arr[i].size(); ++k){
                total2016 += arr[i][k];
            }
        }
    }

    stringstream ss;
    float num2011;
    float num2016;
    for (int i=0; i<animalTypes.size(); ++i){
        ss << setw(19) << right << animalTypes[i];
        for (int k=0; k<yearMap.getKeySize(); ++k){
            if (yearMap.getKeys()[k] == 2011){
                num2011 = float(arr[k][i])/float(total2011) * 100;
                ss << noshowpos << setw(10) << right << fixed << setprecision(1) << num2011;
            }
        }
        for (int k=0; k<yearMap.getKeySize(); ++k){
            if (yearMap.getKeys()[k] == 2016){
                num2016 = float(arr[k][i])/float(total2016) * 100;
                ss << setw(10) << right << fixed << setprecision(1) << num2016;
            }
        }
        ss << showpos << setw(10) << right << fixed << setprecision(1) << (num2016 - num2011);
        reportData->add(num2016 - num2011,ss.str());
        ss.str("");
    }
    return;
    
}
void AnimalTypeReport::printReport()
{
    stringstream ss;
    ss << endl
       << setw(11) << " " << "PERCENTAGE CHANGE OF ANIMALS (2011-2016)" << endl
       << setw(11) << " " << "----------------------------------------" << endl << endl
       << "                         2011      2016     Change" << endl << endl;
    
    ss << *reportData;
    cout << ss.str();

    ofstream outfile("AnimalTypeReport.txt", ios::out);

    if (!outfile){
        cout << "Error: could not open file" << endl;
        return;
    } 

    outfile << ss.str();
    return;
}

#include "sorting.h"
#include <pthread.h>
#include <fstream>
using namespace std;

template <typename T>
void showTime(vector<T> data)
{

    Sorting<T> sortAlgorithms(data);

    vector <vector<T>(Sorting<T>::*)()> ptrsToMethods = sortAlgorithms.getPointersToAllSoringMethods();
    vector<T> result;

    for (unsigned int i = 0; i<ptrsToMethods.size(); i++)
    {
        result = (sortAlgorithms.*ptrsToMethods[i])();
        sortAlgorithms.saveResultToFile(sortAlgorithms.getAlgorithmType() + "_result.txt", result, sortAlgorithms.getAlgorithmType());
    }
}

int main()
{
    //Absolut path to the file with data that should be sort
    string fileName /*= "/home/agnieszka/Projects/Algorithms_origin/float_data.txt"*/;
    cout<<"Enter the absoluth path to your data file..."<<endl;
    cin>>fileName;
    cout<<endl;
    cout<<"Opening file " <<fileName<<"..."<<endl;

    ifstream dataFile;
    dataFile.open(fileName.c_str());

    if(!dataFile.good())
    {
        cout<<"File with data cannot be open"<<endl;
        return 0;
    }

    cout<<"File open correctly..."<<endl;

    bool isString = false;
    vector<double> doubleData;
    float f;
    while (dataFile>>f)
    {
        doubleData.push_back(f);
    }
    if(!dataFile.eof())
    {
        cout<<"Let's sort strings!"<<endl;
        isString = true;
    }
    else
    {
        cout<<"Let's sort doubles!"<<endl;
    }

    vector<string> stringData;
    if(isString)
    {
        dataFile.clear();
        dataFile.seekg(0);
        while (!dataFile.eof())
        {
            string s;
            dataFile>>s;
            if(!dataFile.fail())
            {
                stringData.push_back(s);
            }
        }
        showTime(stringData);
        return 0;
    }
    showTime(doubleData);
    return 0;
}


#include "sortingAlgorithm.h"
#include <pthread.h>
#include <fstream>
using namespace std;

template <typename T>
void computeAll(vector<T> data)
{
    Sorting<T> sortAlgorithms(data);

    vector <vector<T>(Sorting<T>::*)()> ptrsToMethods = sortAlgorithms.getPointersToAllSoringMethods();
    vector<T> result;

    for (unsigned int i = 0; i < ptrsToMethods.size(); i++)
    {
        result = (sortAlgorithms.*ptrsToMethods[i])();
        sortAlgorithms.saveResultToFile(sortAlgorithms.getAlgorithmType() + "_result.txt", result, sortAlgorithms.getAlgorithmType());
    }
}

int main()
{
    string fileName;
    cout << "Enter the absoluth path to your data file..." << endl;
    cin >> fileName;
    cout << endl;
    cout << "Opening file " << fileName << " ..." << endl;

    ifstream dataFile;
    dataFile.open(fileName.c_str());

    if (!dataFile.good())
    {
        cout << "File with data cannot be open" << endl;

        return 0;
    }

    cout << "File open correctly..." << endl;

    bool isString = false;
    vector<double> doubleData;
    float f;
    while (dataFile >> f)
    {
        doubleData.push_back(f);
    }
    if (!dataFile.eof())
    {
        cout << "Let's sort strings!" << endl;
        isString = true;
    }
    else
    {
        cout << "Let's sort doubles!" << endl;
    }

    vector<string> stringData;
    if(isString)
    {
        dataFile.clear();
        dataFile.seekg(0);
        string s;
        while (dataFile >> s)
        {
            dataFile >> s;
            stringData.push_back(s);
        }
        computeAll(stringData);

        return 0;
    }
    computeAll(doubleData);

    return 0;
}


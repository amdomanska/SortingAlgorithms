#include "sortingAlgorithm.h"
#include "stdlib.h"

template <typename T>
void computeAll(std::vector<T> data)
{
    Sorting<T> sortAlgorithms(data);

    std::vector <const std::vector<T>& (Sorting<T>::*)()> ptrsToMethods = sortAlgorithms.getPointersToAllSoringMethods();
    std::vector<T> result;

    for (unsigned int i = 0; i < ptrsToMethods.size(); i++)
    {
        result = (sortAlgorithms.*ptrsToMethods[i])();
        sortAlgorithms.saveResultToFile(sortAlgorithms.getAlgorithmType() + "_result.txt", result, sortAlgorithms.getAlgorithmType());
    }
}

int main()
{
    std::string fileName;
    std::cout << "Enter the absoluth path to your data file..." << std::endl;
    std::cin >> fileName;
    std::cout << endl;

    std::cout << "Opening file " << fileName << " ..." << std::endl;

    std::ifstream dataFile;
    dataFile.open(fileName.c_str());

    if (!dataFile.good())
    {
        std::cout << "File with data cannot be open" << std::endl;

        return EXIT_FAILURE;
    }

    std::cout << "File open correctly..." << std::endl;

    bool isString = false;
    std::vector<double> doubleData;
    float f;
    while (dataFile >> f)
    {
        doubleData.push_back(f);
    }
    if (!dataFile.eof())
    {
        std::cout << "Let's sort strings!" << std::endl;
        isString = true;
    }
    else
    {
        std::cout << "Let's sort doubles!" << std::endl;
    }

    std::vector<std::string> stringData;
    if (isString)
    {
        dataFile.clear();
        dataFile.seekg(0);
        std::string s;
        while (dataFile >> s)
        {
            dataFile >> s;
            stringData.push_back(s);
        }
        computeAll(stringData);

        return EXIT_SUCCESS;
    }
    computeAll(doubleData);

    return EXIT_SUCCESS;
}


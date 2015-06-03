#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <fstream>
#include <vector>

#include "overloadedOperators.h"
using namespace std;

template <typename T>
class Algorithm
{
protected:
    vector<T>* inData;
    int dataSize;

    vector<T> createResultVector()
    {
        vector<T> result;
        for (int i = 0; i < dataSize; i++)
        {
            result.push_back((*inData)[i]);
        }

        return result;
    }

public:
    Algorithm(vector<T>& in)
    {
        dataSize = in.size();
        inData = &in;
    }

    Algorithm(const Algorithm& object)
    {
        this->inData = object.inData;
        this->dataSize = object.dataSize;
    }
};

#endif // ALGORITHM_H

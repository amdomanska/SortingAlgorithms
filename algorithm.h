#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <fstream>
#include <vector>

#include "overloadedOperators.h"

template <typename T>
class Algorithm
{
protected:
    std::vector<T> inData;
    int dataSize;

    std::vector<T> createResultVector()
    {
        std::vector<T> result;
        for (int i = 0; i < dataSize; i++)
        {
            result.push_back(inData[i]);
        }

        return result;
    }

public:
    Algorithm(const std::vector<T>& in)
    {
        dataSize = in.size();
        for (int i = 0; i < dataSize; i++)
        {
            inData.push_back((in)[i]);
        }
    }

    Algorithm(const Algorithm& object)
    {
        this->inData = object.inData;
        this->dataSize = object.dataSize;
    }
};

#endif // ALGORITHM_H

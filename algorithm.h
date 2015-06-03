#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <fstream>
#include <vector>
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
        for (int i = 0; i<dataSize; i++)
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

    Algorithm( const Algorithm& object)
    {
        this->inData = object.inData;
        this->dataSize = object.dataSize;
    }
};

bool operator<(string a, string b)
{
    unsigned int i = 0;
    while(a[i]==b[i])
    {
        i++;
        if (i==a.size()) return true;
        else if (i==b.size()) return false;
    }
    return a[i]<b[i];
}

bool operator>(string a, string b)
{
    unsigned int i = 0;
    while(a[i]==b[i])
    {
        i++;
        if (i==a.size()) return true;
        else if (i==b.size()) return false;
    }
        return a[i]>b[i];
}

bool operator>=(string a, string b)
{
    return (a>b || (a.compare(b) == 0));
}

#endif // ALGORITHM_H

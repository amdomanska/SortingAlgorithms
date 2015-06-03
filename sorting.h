#ifndef SORTING_H
#define SORTING_H

#include <fstream>
#include <iterator>
#include "algorithm.h"

template <typename T>
class Sorting : public Algorithm<T>
{
private:
    vector<T> bubbleResult;
    vector<T> heapResult;
    vector<T> mergeResult;
    vector<T> insertResult;
    vector<T> quickResult;
    string algorithmType;
    vector <vector<T>(Sorting<T>::*)()> ptrsToMethods;
public:

    Sorting(vector<T>& in) : Algorithm<T>(in)
    {
    }

    vector<T> computeBubbleSort()
    {
        algorithmType = "BubbleSort";
        bubbleResult = this->createResultVector();
        for (int i = 1; i<this->dataSize; i++)
        {
            for (int j = this->dataSize-1; j>=i; j--)
            {
                if(this->bubbleResult[j] < this->bubbleResult[j-1])
                {
                    swap(this->bubbleResult[j-1], this->bubbleResult[j]);
                }
            }
        }
        return bubbleResult;
    }

    vector<T> computeHeapSort(){
        algorithmType = "HeapSort";
        heapResult = this->createResultVector();
        int heapSize = this->dataSize;
        for (int i = heapSize/2; i>0; i--)
        {
            shiftUp(i,heapSize, heapResult);
        }
        while(heapSize>1)
        {
            swap(this->heapResult[0], this->heapResult[heapSize-1]);
            heapSize--;
            shiftUp(1,heapSize, heapResult);
        }
        return heapResult;
    }

    vector<T> computeMergeSort()
    {
        algorithmType = "MergeSort";
        mergeResult = this->createResultVector();
        computeMerge(0, this->dataSize-1,mergeResult);

        return mergeResult;
    }

    vector<T> computeInsertSort()
    {
        algorithmType = "InsertSort";
        insertResult = this->createResultVector();
        for (int i=1; i<this->dataSize; i++)
        {
            int j=i;
            T tmp = this->insertResult[j];
            while((j>0) && (this->insertResult[j-1])>tmp)
            {
                this->insertResult[j]=this->insertResult[j-1];
                j--;
            }
            this->insertResult[j]=tmp;
        }
        return insertResult;
    }

    vector<T> computeQuickSort()
    {
        algorithmType = "QuickSort";
        quickResult = this->createResultVector();
        computeQuick(0,this->dataSize-1,quickResult);

        return quickResult;
    }

    string getAlgorithmType()
    {
        return this->algorithmType;
    }

    void saveResultToFile(string fileName, vector<T>& result, string algorithmType = "")
    {
        cout<<"saving result of "<<algorithmType<<" to file "<<fileName<<endl;
        ofstream output_file(fileName.c_str());
        ostream_iterator<T> output_iterator(output_file, "\n");
        copy(result.begin(), result.end(), output_iterator);
    }

    vector <vector<T>(Sorting<T>::*)()> getPointersToAllSoringMethods(){

        ptrsToMethods.push_back(&Sorting<T>::computeBubbleSort);
        ptrsToMethods.push_back(&Sorting<T>::computeHeapSort);
        ptrsToMethods.push_back(&Sorting<T>::computeInsertSort);
        ptrsToMethods.push_back(&Sorting<T>::computeMergeSort);
        ptrsToMethods.push_back(&Sorting<T>::computeQuickSort);

        return ptrsToMethods;
    }

private:
    void shiftUp(int pos, int heapSize, vector<T>& data)
    {
        int j;
        T val = data[pos-1];
        while(pos <= heapSize/2)
        {
            j = 2*pos;
            if((j<heapSize) && (data[j-1] < data[j]))
            {
                j++;
            }
            if(val >= data[j-1])
            {
                break;
            }
            else
            {
                data[pos-1] = data[j-1];
                pos=j;
            }
        }
        data[pos-1] = val;
    }

    void merge(int firstPos, int midPos, int lastPos, vector<T>& data)
    {
        T aux[this->dataSize];
        int leftFirstPos = firstPos;
        int leftLastPos = midPos;
        int rightFirstPos = midPos+1;
        int rightLastPos = lastPos;

        int i = leftFirstPos;

        while((leftFirstPos <= leftLastPos) && (rightFirstPos <= rightLastPos))
        {
            if(data[leftFirstPos] < data[rightFirstPos])
            {
                aux[i] = data[leftFirstPos];
                leftFirstPos++;
            }
            else
            {
                aux[i] = data[rightFirstPos];
                rightFirstPos++;
            }
            i++;
        }

        while(leftFirstPos <= leftLastPos)
        {
            aux[i] = data[leftFirstPos];
            leftFirstPos++;
            i++;
        }
        while(rightFirstPos <= rightLastPos)
        {
            aux[i] = data[rightFirstPos];
            rightFirstPos++;
            i++;
        }

        for (int i = firstPos; i <= lastPos; i++)
        {
            data[i] = aux[i];
        }
    }

    void computeMerge(int firstPos, int lastPos, vector<T>& data)
    {
        if (firstPos < lastPos)
        {
            int midPos = (firstPos + lastPos)/2;
            this->computeMerge(firstPos, midPos,data);
            this->computeMerge(midPos+1, lastPos,data);
            this->merge(firstPos, midPos, lastPos,data);
        }
    }

    void computeQuick(int left, int right, vector<T>& data)
    {
        if(left < right){
            int m = left;
            for (int i = left+1; i<=right; i++)
            {
                if(data[i]<data[left]) swap(data[++m], data[i]);
            }
            swap(data[left],data[m]);
            this->computeQuick(left,m-1,data);
            this->computeQuick(m+1,right,data);
        }
    }
};

#endif // SORTING_H

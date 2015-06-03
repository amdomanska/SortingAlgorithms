#ifndef MERGESORT_H
#define MERGESORT_H

#include "algorithm.h"

template <typename T>
class MergeSort : public Algorithm <T> {
private:
    void merge(int firstPos, int midPos, int lastPos){
        T aux[this->dataSize];
        int leftFirstPos = firstPos;
        int leftLastPos = midPos;
        int rightFirstPos = midPos+1;
        int rightLastPos = lastPos;

        int i = leftFirstPos;

        while((leftFirstPos <= leftLastPos) && (rightFirstPos <= rightLastPos)){
            if(this->data[leftFirstPos] < this->data[rightFirstPos]){
                aux[i] = this->data[leftFirstPos];
                leftFirstPos++;
            }
            else{
                aux[i] = this->data[rightFirstPos];
                rightFirstPos++;
            }
            i++;
        }

        while(leftFirstPos <= leftLastPos){
            aux[i] = this->data[leftFirstPos];
            leftFirstPos++;
            i++;
        }
        while(rightFirstPos <= rightLastPos){
            aux[i] = this->data[rightFirstPos];
            rightFirstPos++;
            i++;
        }

        for (int i = firstPos; i <= lastPos; i++)
            this->data[i] = aux[i];
    }

    void compute(int firstPos, int lastPos){
        if (firstPos < lastPos){
            int midPos = (firstPos + lastPos)/2;
            this->compute(firstPos, midPos);
            this->compute(midPos+1, lastPos);
            this->merge(firstPos, midPos, lastPos);
        }
    }

public:

    MergeSort(vector<T>& in) : Algorithm<T>(in){}



    void displayData(){
        cout<<"(Merge sort)"<<endl;
        Algorithm<T>::displayData();
    }
};

#endif // MERGESORT_H

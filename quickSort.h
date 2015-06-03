#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "algorithm.h"

template <typename T>
class QuickSort : public Algorithm <T> {
private:
    void compute(int left, int right){
        if(left < right){
            int m = left;
            for (int i = left+1; i<=right; i++)
                if(this->data[i]<this->data[left]) swap(this->data[++m], this->data[i]);
            swap(this->data[left],this->data[m]);
            this->compute(left,m-1);
            this->compute(m+1,right);
        }
    }

public:

    QuickSort(vector<T>& in) : Algorithm<T>(in){}



    void displayData(){
        cout<<"(Quick sort)"<<endl;
        Algorithm<T>::displayData();
    }
};

#endif // QUICKSORT_H

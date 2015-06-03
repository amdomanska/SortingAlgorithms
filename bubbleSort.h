#ifndef BUBBLE_H
#define BUBBLE_H

#include "algorithm.h"

template <typename T>
class BubbleSort : public Algorithm <T> {
public:

    BubbleSort(vector<T>& in) : Algorithm<T>(in){}
    void compute(){
        for (int i = 1; i<this->dataSize; i++){
            for (int j = this->dataSize-1; j>=i; j--){
                if(this->data[j] < this->data[j-1]) swap(this->data[j-1], this->data[j]);
            }
        }
    }

    void displayData(){
        cout<<"(Bubble sort)"<<endl;
        Algorithm<T>::displayData();
    }

};

#endif // BUBBLE_H

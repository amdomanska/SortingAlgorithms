#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "algorithm.h"

template <typename T>
class HeapSort : public Algorithm <T> {
private:


public:

    HeapSort(vector<T>& in) : Algorithm<T>(in){}



    void displayData(){
        cout<<"(Heap sort)"<<endl;
        Algorithm<T>::displayData();
    }
};

#endif // HEAPSORT_H

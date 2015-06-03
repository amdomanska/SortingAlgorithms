#ifndef INSERTSORT_H
#define INSERTSORT_H

#include "algorithm.h"

template <typename T>
class InsertSort : public Algorithm <T> {
public:

    InsertSort(vector<T>& in) : Algorithm<T>(in){
    }



    void displayData(){
        cout<<"(Insert sort)"<<endl;
        Algorithm<T>::displayData();
    }
};

#endif // INSERTSORT_H

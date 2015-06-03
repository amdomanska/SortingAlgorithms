#include "algorithm.h"r

template <typename T>
Algorithm<T>::Algorithm(T* in, int inSize){
    cout<<"Algorithm constructor"<<endl;
    dataSize = inSize;
    data = new T[dataSize];
    for (int i = 0; i<dataSize; i++)
        data[i] = in[i];
}

template <typename T>
void Algorithm<T>::compute(){
    cout<<"Virtual method Algorith<T>::compute()"<<endl;
}

template <typename T>
void Algorithm<T>::displayData(){
    for (int i = 0; i<dataSize; i++){
        cout<<data[i]<<endl;
    }
}

template <typename T>
Algorithm<T>::~Algorithm(){
    cout<<"Destructor Algorithm"<<endl;
    delete[] data;
}

bool operator<(string a, string b){
if (a.size() != b.size()) return (a.size() < b.size());
else{
    int i = 0;
    while(a[i]==b[i]) i++;
    return a[i]<b[i];
}
}

bool operator>(string a, string b){
if (a.size() != b.size()) return (a.size() > b.size());
else{
    int i = 0;
    while(a[i]==b[i]) i++;
    return a[i]>b[i];
}
}

bool operator>=(string a, string b){
return (a>b || (a.compare(b) == 0));
}

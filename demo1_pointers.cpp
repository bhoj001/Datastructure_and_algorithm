/*
Author: Bhoj bahadur karki
Date: 2020-Jan-14th
Purpose: understanding pointers in c++
Licence: MIT license (MIT)
*/

#include <iostream>
using namespace std;
const int MAX = 3;

void simple_array(){
    int var[MAX]= {20,30,40};

    for(int i=0;i<MAX;i++){
        cout << "value at var["<<i<<"]="<<var[i]<<endl;
    }
}

void array_with_pointers(){
    int var[MAX]= {20,30,40};
    int *ptr[MAX];
    
    for(int i=0;i<MAX;i++){
        ptr[i]=&var[i];
    }

    for(int i=0;i<MAX;i++){
        cout << "using pointer value at var["<<i<<"]="<<*ptr[i]<<endl;
    }
}

int main(){

    simple_array();
    array_with_pointers();

    return 0;
}
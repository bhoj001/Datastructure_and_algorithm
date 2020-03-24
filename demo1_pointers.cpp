/*
Author: Bhoj bahadur karki
Date: 2020-Jan-14th
Purpose: understanding pointers in c++
Licence: MIT license (MIT)
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
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

    // copy to ptr
    for(int i=0;i<MAX;i++){
        cout << "address="<<&var[i]<<",value="<<var[i]<<endl;
        ptr[i]=&var[i];
    }

    // print value in the pointer array
    for(int i=0;i<MAX;i++){
        cout << "using pointer value at var["<<i<<"]="<<*ptr[i]<<endl;
    }
}

void array_of_pointers(){
    const char *name[MAX]= {"bhoj bahadur karki","ramesh","john"};
    
    // here (name+i) shows value at that pointer location
    // name+i increments the pointer location appropriately i.e.performs arithmetic operation on pointer address
     for(int i=0;i<MAX;i++){
        cout<<"--------------------------"<<endl;
        cout << "names: address at name["<<i<<"]="<<name+i<<endl;
        cout << "names: value at name["<<i<<"]="<<*(name+i)<<endl;
    }
}

void with_variable_pointer_to_pointer(){
    int var,*ptr,**pptr,***ppptr;
    var = 333;
    ptr = &var;
    pptr=&ptr; //ptr is a pointer,and pptr is pointer to pointer
    ppptr=&pptr;

    cout << "value of var = "<<var<<endl;

    cout << "address of ptr = "<<ptr<<endl;
    cout << "value of ptr = "<<*ptr<<endl;
    
    cout << "address of pptr = "<<pptr<<endl;
    cout << "value of pptr = "<<**pptr<<endl;     
    
    cout << "address of ppptr = "<<ppptr<<endl;
    cout << "value of ppptr = "<<***ppptr<<endl;       
}

void with_array_pointer_to_pointer(){

    int var[MAX]={33,44,55};
    int *ptr[MAX],**pptr[MAX];

    // COPY
    for(int i=0;i<MAX;i++){
        ptr[i]=&var[i];
    }

    // COPY
    for(int i=0;i<MAX;i++){
        pptr[i]=&ptr[i];// address of pointers
    }

    // print to console
    for(int i=0;i<MAX;i++){
        cout << "-------------------------"<<endl;
        cout << "address of pptr["<<i<<"]="<<pptr[i]<<endl;
        cout << "value of pptr["<<i<<"]="<<**pptr[i]<<endl;
    }


}

unsigned long get_seconds(unsigned long *par){
    unsigned long x = time_t(par);
    return x;
}

void call_get_seconds(){
    unsigned long sec=400;
    get_seconds( &sec );
    // print the actual value
    cout << "Number of seconds :" << sec << endl;
}

float get_average(int *arr, int length){
    float sum = 0;
    for(int i=0;i<length;i++){
        sum += arr[i];
    }
    return(sum/length);
}

float passing_array_to_function(){
    int var[MAX]= {20,30,40};
    float avg = get_average(var,MAX);
    cout << "average value ="<<avg<<endl;
}

int *get_random_number(){
    static int r[10];
    // set the seed for random number
    srand( (unsigned)time( NULL ) );
    for(int i =0;i<10;i++){
        r[i]=rand();
    }

    return r;
}

void print_random_number(){
    int *p;
    p = get_random_number();
    for(int i=0;i<10;i++){
        cout << "*(p + "<<i<<") :"<<*(p+i)<<endl;
    }
}



int main(){

    simple_array();
    array_with_pointers();
    array_of_pointers();
    with_variable_pointer_to_pointer();
    with_array_pointer_to_pointer();
    call_get_seconds();
    passing_array_to_function();
    print_random_number();
    
    return 0;
}

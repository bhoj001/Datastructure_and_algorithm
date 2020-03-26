#include <stdio.h>
#include<stdbool.h>

#define MAX 10
/*
Author: Bhoj Bahadur Karki
purpose : Bubble sorting algorithm.
date: 2020-March-26th
*/

// array initialization 
int array_storage[MAX] = {2,99,33,44,11,55,55676,77,85,6};


void DisplayItem(){

    printf("[");
    int c;
    for(c = 0; c < MAX;c++){
        printf("%d, ",array_storage[c]);
    }
    printf("]\n");
}

void BubbleSort(){
    int temp;
    bool swapping = false;
    for(int i=0;i<MAX-1;i++){
        swapping = false;

        for(int j =0;j<MAX-1-i;j++){

            if(array_storage[j]>array_storage[j+1]){
                    temp = array_storage[j];
                    array_storage[j]=array_storage[j+1];
                    array_storage[j+1]=temp;
                swapping = true;
                printf("\nswapped item (%d,%d)",array_storage[j],array_storage[j+1]);
            }else{
                printf("\nNot swapping");
           }
        }
        if(!swapping){
            // item are sorted 
            break;
        }
        printf("\nIteriation : %d ",i+1);
        DisplayItem();
    }
}


int main(){
    DisplayItem();

    BubbleSort();

    DisplayItem();
}


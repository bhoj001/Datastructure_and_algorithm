#include <stdio.h>
#include<stdbool.h>

#define MAX 10
/*
Author: Bhoj Bahadur Karki
purpose : Insertion sort algorithm.
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

void InsertionSort(){
    int valueToBeInserted, holePosition,i;
   
    for(i=1;i<MAX;i++){
      

        valueToBeInserted = array_storage[i];

        holePosition =i;
        while(holePosition >0 && array_storage[holePosition-1]>valueToBeInserted){
            array_storage[holePosition]=array_storage[holePosition-1];
            holePosition--;
            printf("\nitem moved %d,",array_storage[holePosition]);
        }

        if (holePosition != i){
            printf("\n item %d inserted at %d",valueToBeInserted,holePosition);
            // insert the number at hole position
            array_storage[holePosition]=valueToBeInserted;
        }
        
        printf("\nIteriation : %d ",i);
        DisplayItem();
    }
}


int main(){
    DisplayItem();

    InsertionSort();
    
    DisplayItem();
}


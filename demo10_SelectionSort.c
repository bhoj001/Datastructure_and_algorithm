#include <stdio.h>
#include<stdbool.h>

#define MAX 10
/*
Author: Bhoj Bahadur Karki
purpose : Selection Sort algorithm.
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

void SelectionSort(){
    
    for(int i=0;i<MAX-1;i++){
        int min = i;

        for(int j =i+1;j< MAX;j++){

            if (array_storage[min]>array_storage[j]){
                min = j;
            }
        }
        if(min != i){
        // swap values 
            printf("\nItems swapped: [ %d, %d ]\n" , array_storage[i], array_storage[min]);
            int temp = array_storage[min];
            array_storage[min]=array_storage[i];
            array_storage[i]=temp;
        }
        printf("\nIteriation : %d ",i+1);
        DisplayItem();
    }
}


int main(){
    DisplayItem();

    SelectionSort();

    DisplayItem();
}


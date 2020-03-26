#include <stdio.h>
#include<stdbool.h>

#define MAX 10
/*
Author: Bhoj Bahadur Karki
purpose : Quick Sort algorithm.
date: 2020-March-26th
*/

// array initialization 
int array_storage[MAX] = {2,99,33,11,11,55,55676,77,85,6};


void DisplayItem(){

    printf("[");
    int c;
    for(c = 0; c < MAX;c++){
        printf("%d, ",array_storage[c]);
    }
    printf("]\n");
}

void Swap(int num1,int num2){
    int temp = array_storage[num1];
    array_storage[num1]= array_storage[num2];
    array_storage[num2]=temp;
}

int PartitionItem(int left,int right, int pivot){
    int leftPointer = left-1;
    int rightPointer = right;

    while (true){
        
        while (array_storage[++leftPointer] < pivot)
        {
        // do nothing
        }

        while (rightPointer >0 && array_storage[--rightPointer] >pivot)
        {
        // do nothing
        }

        if(leftPointer >= rightPointer){
            break;
        }else{
            printf("\nItem swapped:(%d,%d)",array_storage[leftPointer],array_storage[rightPointer]);
            Swap(leftPointer,rightPointer);
        }
    }

    printf("\nItem swapped:(%d,%d)",array_storage[leftPointer],array_storage[right]);
    Swap(leftPointer,right);
    printf("\nupdated array:");
    DisplayItem();
    return leftPointer;
    
}

void  QuickSort(int left,int right){

    if (right-left <= 0){
        return;
    } else{
        int pivot = array_storage[right];
        int partition = PartitionItem(left,right,pivot);
        QuickSort(left,partition-1);
        QuickSort(partition+1,right);
    }
   
}


int main(){
    DisplayItem();

    QuickSort(0,MAX-1);
    
    DisplayItem();
}


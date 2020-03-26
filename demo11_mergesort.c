#include <stdio.h>
#include<stdbool.h>

#define MAX 10
/*
Author: Bhoj Bahadur Karki
purpose : Merge sort algorithm.
date: 2020-March-26th
*/

// array initialization 
int a[11] = {2,99,33,44,11,55,55676,77,85,6,0};
int b[10];



void DisplayItem(){

    printf("[");
    int c;
    for(c = 0; c < 11;c++){
        printf("%d, ",a[c]);
    }
    printf("]\n");
}

void Merging(int low,int mid, int high){
    int l1,l2,i;
    for(l1=low,l2=mid+1,i=low ; l1<=mid && l2<=high ; i++){

        if(a[l1]<=a[l2]){
            b[i]=a[l1++];
        }else{
            b[i]=a[l2++];
        }
    }// close of for loop

    while(l1<=mid){
        b[i++]=a[l1++];
    }

    while (l2 <= high){
        b[i++]=a[l2++];
    }

    for(i=low;i<=high;i++){
        a[i]=b[i];
    }

}

void MergeSort(int low,int high){
    int mid;

    if(low<high){
        mid = (low+high)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merging(low,mid,high);
    }
    else{
        return;
    }

}


int main(){
    printf("before merging:");
    DisplayItem();

    MergeSort(0,MAX);

    DisplayItem();
}


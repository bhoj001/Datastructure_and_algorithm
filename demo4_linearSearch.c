#include <stdio.h>

#define MAX 10
/*
Author: Bhoj Bahadur Karki
purpose : Linear Search algorithm testing.
date: 2020-March-25th
*/

// array initialization 
int array_storage[MAX] = {2,33,44,11,55,22,55676,77,85,6};

int FindData(int search_item){
    int index  = -1;
    int comparision = 0;
    for(int i = 0;i < MAX;i++){
        comparision++;
        if (search_item == array_storage[i]){
            index = i;
            break;
        }
    }
    printf("\ncomparision made = %d",comparision);
    return index;
}

int main(){

    int searchvalue = 55;
    int x = FindData(searchvalue);
    if (x == -1){
        printf("\nNo item found");
    }else{
        printf("\nItem found at %d index ",x);
    }
}


#include <stdio.h>

#define MAX 10
/*
Author: Bhoj Bahadur Karki
purpose : Linear Search algorithm testing.
date: 2020-March-25th
Notes: Runtime complexity of Binary search algorithm is  Ο(log n) 
*/

// array initialization 
int array_storage[MAX] = {2,6,22,33,44,55,77,82,94,160};

int FindUsingBinarySearch(int value){
    /*
    Algo. for binary search
    1. arrange the item in ascending order
    2. calculate the mid term and compare
    3. if mid term is equal we we have our element.
    4. else if mid term is > value then , item is in lower half else item is in upper half
    5. repeat 2 to 4 again until we find element or upper_bound  > lower_bound 
    */

    int lower_bound = 0, upper_bound = MAX-1;
    int comparision = 0;
    int mid_point = -1;
    int index = -1;

    while(lower_bound <= upper_bound){

        printf("\nLower bound values: index=  %d, value = %d ",lower_bound, array_storage[lower_bound]);
        printf("\nupper bound values: index=  %d, value = %d ",upper_bound, array_storage[upper_bound]);
        comparision++;
        printf("\ncomparision=  %d ",comparision);
    
        // NOTE: HERE WE CAN NOT DO LIKE (lower_bound+(upper_bound+lower_bound))/2 this will be error.
        mid_point = lower_bound + (upper_bound-lower_bound)/2;
        printf("\nmid point  = %d",mid_point);
        printf("\n--------------------------");

        if (array_storage[mid_point]==value){
            index = mid_point;
            break;
        }else{

            if (array_storage[mid_point]< value){
                // data is in upper half
                 lower_bound = mid_point+1;
            }else{
                // data is in lower half
                upper_bound = mid_point-1;
            }
        }
    }
    printf("\nTotal comparision =%d",comparision);
    

    return index;
}

int main(){

    int search_item = 160;

    int found = FindUsingBinarySearch(search_item);

    if (found != -1){
        printf("\nItem found %d at %d",search_item,found);
    }else{
        printf("\nThere is no item %d",search_item);
    }

    return 0;
}
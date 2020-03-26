#include <stdio.h>
int fxn(){
    int item = 0;
    while(item != 3){
        item++;
        printf("\nitem=%d",item);
        if (item == 2){
            // if we return like this we stop a loop in c
            return item;
        }

    }
}


int main(){
    fxn();

    int arr[]={10,20,30,40,50,60};
    // 1. arr[3]==3[arr] e.g. array[n]== n[array]
    if (arr[3]==3[arr]){
        // note arr[3]=40 and 3[arr]=40 as well 
        printf("\nC is awesome and confusing %d %d",arr[3],3[arr]);
    }else{
        printf("\nnot allowed");
    }

}
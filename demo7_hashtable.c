#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
    int data;
    int key;
};

struct DataItem * HashArray[SIZE];
struct DataItem * DummyItem;
struct DataItem * Item;

int HashCode(int key){
    return key % SIZE;
}

// Search Item

struct DataItem * SearchUsingKey(int key){

    // get hash code
    int hashindex = HashCode(key);


    while(HashArray[hashindex]!= NULL){
        if (HashArray[hashindex]->key == key){
            // found return item 
            return HashArray[hashindex];
        }else{
            ++hashindex;
            hashindex %= SIZE;
        }
    }
    return NULL;
}
// Insert item 
void Insert(int key, int data){
    struct DataItem * item = (struct DataItem*)malloc(sizeof(struct DataItem));

    item->key = key;
    item->data = data;

    // get hashindex 
    int hashindex = HashCode(key);

    // find appropriate position 
    while(HashArray[hashindex] != NULL && HashArray[hashindex]->key != -1){
        // move to next index
        ++hashindex;
        hashindex %= SIZE;
    }

    HashArray[hashindex] =item;
}

// Deletion of items
struct DataItem *Delete(struct DataItem * item){
    int key = item->key;
    // get hashindex
    int hashindex = HashCode(key);

    while (HashArray[hashindex] != NULL){

        if (HashArray[hashindex]->key == key){
            // return HashArray[hashindex];
            struct DataItem* temp = HashArray[hashindex];
            // assign dummy value to deleted position.
            HashArray[hashindex]= DummyItem;
            return temp;
        }
        
        // GET THE NEXT INDEX
        ++hashindex;

        // based on table index
        hashindex %= SIZE;

    }

return NULL;
}

void DisplayHashArray(){

    printf("[");
    int i = 0;
    
    for(i = 0; i<SIZE;i++){
        if (HashArray[i] != NULL)
            printf("(%d,%d),",HashArray[i]->key,HashArray[i]->data);
        else
        {
            printf("--,");
        }
        
    }
    printf("]\n");
}



int main(){ 

    DummyItem =  (struct DataItem*)malloc(sizeof(struct DataItem));
    DummyItem->data = -1;
    DummyItem->key = -1;

    printf("before insert \n HashTable=");
    DisplayHashArray();
    // insert item
    Insert(1, 20);
    Insert(2, 70);
    Insert(42, 2);
    Insert(4, 25);
    Insert(12, 2);
    Insert(14, 32);
    Insert(17, 11);
    Insert(13, 78);
    Insert(37, 97);

    printf("AFTER insert \n HashTable=");
    DisplayHashArray();

    // search key
    printf("\nsearch item with key 14:");
    Item = SearchUsingKey(14);
    if (Item != NULL){
        printf("\nItem found (%d,%d)",Item->key,Item->data);
    }else{
        printf("\nItem not found");
    }

    // delete item
    // item is already defined above
    printf("\n\ndelete 14");
    Item = Delete(Item);
    // Once delete search again
    printf("\nsearch item with key 14:");
    Item = SearchUsingKey(14);
    if (Item != NULL){
        printf("\nItem found (%d,%d):",Item->key,Item->data);
    }else{
        printf("\nItem not found");
    }


    // print the hash table
    printf("\nFinal HashTable=");
    DisplayHashArray();

}



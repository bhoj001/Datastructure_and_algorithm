#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct LinkedListNode {
    int data;
    int key;
    struct LinkedListNode *next;
};

struct LinkedListNode *head = NULL;
struct LinkedListNode *current = NULL;

// display the list 
void PrintLinkedList(){
    struct LinkedListNode *ptr = head;

    printf("[");

    while (ptr != NULL){
        printf("(%d,%d),",ptr->key,ptr->data);
        ptr = ptr->next;
    }
    printf("]");

}

void InsertFirst(int key, int data){
    // Algorithm
    // 1. create link using malloc, 
    // 2. assign data value,
    // 3. point this to new link using head
    // 4. point head to this link
    struct LinkedListNode* link = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    
    link->data = data;
    link->key  =  key;

    // point to old data first
    link->next = head;

    // point head to newly created node
    head = link;

}

struct LinkedListNode* DeleteFirstItem(){
    // Algo.
    // 1. get head reference
    // 2. point head to next item of first item, note head is 
    // already point to first item, head->next point to 2nd item
    // 3. return the temp list at this point we might want to free memory allocation of temp node 
    struct LinkedListNode *tempNode = head;

    // head points to next element in the list, skipping the first node in the list
    head = head->next;

    return tempNode;
}

// check if list is empty 
bool IsEmpty(){
    return head == NULL;
}

// calibrate lenght of linked list
int Length(){
    int length = 0;

    struct LinkedListNode *current;

    for(current = head;current != NULL;current = current->next){
        
        length++;

    }
    return length; 
}

struct LinkedListNode* FindUsingKey(int key){
    /*
       Algo
       1. start current node with head
       2. check is list is empty
       3. travers key until you find it if not found then return NULL.
    */
    struct LinkedListNode *current = head;

    // Check empty case
    if (head == NULL){
        return NULL;
    }
    // check each item
    while(current->key != key){
        if (current->next == NULL){
            return NULL; // return NULL if nothing is found at the end.
        }else{
            current= current->next;
        }
    }
    return current;
}

struct LinkedListNode * Delete(int key){
    /*
    Algo:
    1. find the key and delete it
    */
   struct LinkedListNode *current = head;
   struct LinkedListNode *prev_node = NULL;

    // Check empty case
    if (head == NULL){
        return NULL;
    }
    // check each item
    while(current->key != key){
        if (current->next == NULL){
            return NULL; // return NULL if nothing is found at the end.
        }else{
            // first point to previous node
            prev_node = current;
            // point current to next i.e. change current node to next node
            current= current->next;        
        }
    }

    // if it is found we point previous to next and
    if(current==head){
        // point head to 2nd node escaping 1st node
        head= head->next;
    } else{
        prev_node->next = current->next;
    }
    
    // return the deleted node link
    return current;
}

void SortItem(){

    struct LinkedListNode *current, *next;
    int temp_data, temp_key;
    
    int length = Length();
    int k = length;

    for(int i = 0; i < length-1 ; i++,k-- ){
        current = head;
        next = head->next;
        for(int j=1; j<k; j++){
           
            if(current->data > next->data){
                // swap , test later
    
                temp_data= current->data;
                current->data = next->data;
                next->data = temp_data;

                temp_key = current->key;
                current->key = next->key;
                next->key= temp_key;    

            }

            current = current->next;
            next= next->next;
        }
    }
}

void ReverseItem(struct LinkedListNode** head_ref){
    struct LinkedListNode* prev   = NULL;
    struct LinkedListNode* current = *head_ref;
    struct LinkedListNode* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;

}

int main(){

    InsertFirst(1,10);
    InsertFirst(2,20);
    InsertFirst(3,50);
    InsertFirst(4,33);
    InsertFirst(5,55);
    InsertFirst(6,79);

    // print the list
    PrintLinkedList();
    printf("\nlength = %d ",Length());

    // deleting item and reprinting

    while(!IsEmpty()){  // or we can do: while(head != NULL){}
        // Keep deleting first item until all deleted
        struct LinkedListNode * deleteditem = DeleteFirstItem();
        printf("\ndeleted item: (%d,%d) ",deleteditem->key,deleteditem->data);

        // after deleting free memory, free() is used to free the memory location
        free(deleteditem); // release the memory.
    }

    // print 
    printf("\nafter deleting print\nList= ");
    PrintLinkedList();
    printf("\nlength = %d ",Length());

    InsertFirst(1,10);
    InsertFirst(2,3);
    InsertFirst(3,20);
    InsertFirst(4,50);
    InsertFirst(5,33);
    InsertFirst(6,55);
    InsertFirst(7,79);
    printf("\nInsertion again\nList= ");
    PrintLinkedList();
    printf("\nlength = %d ",Length());

    printf("\nSorted item =\n ");
    SortItem();
    PrintLinkedList();

    // Deleting item using
    struct LinkedListNode *deleted_item =  Delete(4);
    // one it's delete free the memory
    free(deleted_item);

    printf("\nafter deleting key=4 =\n ");
    PrintLinkedList();

    // find element with index 6,
    struct LinkedListNode * founditem = FindUsingKey(5);

    if (founditem != NULL){
        printf("\nFound item = (%d,%d)",founditem->key,founditem->data);
    }
    else
    {
        printf("\nNo item found");
    }

    // check if empty
    bool value = IsEmpty();
    if( value == true){
        printf("\nList is empty!");
    }else{
        printf("\nThere are some items in the list!");
    }

    // test reverse
    ReverseItem(&head);
    printf("\nafter reversing list =\n ");
    PrintLinkedList();

    return 0;
}


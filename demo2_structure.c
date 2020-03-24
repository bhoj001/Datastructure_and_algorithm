#include <stdio.h>
#include <string.h>

struct Book { 

    char book_name[50];
    char author[30];
    int book_id;

};

struct StudentData{
    char *stu_name;
    int stu_id;
    int stu_age;
};

// structure within structure
struct stu_address
{
     int street;
     char *state;
     char *city;
     char *country;
};
// structure within structure
struct stu_data
{
    int stu_id;
    int stu_age;
    char *stu_name;
    struct stu_address stuAddress;
};




// function declaration
// since function defined is after it is called we need to declare before it's called.
void PrintStructure(struct Book book);
void PrintUsingPointer(struct Book *book);


int main(){
    // declaring structure 
    struct Book book1;
    struct Book book2;

    strcpy(book1.book_name,"A monk who sold his ferari");
    strcpy(book1.author,"Robin Sharma");
    book1.book_id = 20888091;

    // book2.book_name = "Mahabarat";
    // book2.author = "someone";
    strcpy(book2.book_name,"good habits");
    strcpy(book2.author,"rajesh ");
    book2.book_id = 566433;

    printf("book name = %s \n",book1.book_name);
    printf("book author = %s \n",book1.author);
    printf("book id = %d \n",book1.book_id);
    

    printf("book name = %s \n",book2.book_name);
    printf("book author = %s \n",book2.author);
    printf("book id = %d \n",book2.book_id);

    // call the function 
    PrintStructure(book1);

    PrintUsingPointer(&book2);

    struct StudentData s1;
    s1.stu_name = "Hari prasad";
    s1.stu_id = 556649;
    s1.stu_age = 27;

    printf("Student Name is: %s", s1.stu_name);
    printf("\nStudent Id is: %d", s1.stu_id);
    printf("\nStudent Age is: %d", s1.stu_age);

    struct stu_data s2;
    s2.stu_age = 33;
    s2.stu_name = "Ramesh prashad sharma";
    s2.stu_id = 44;
    s2.stuAddress.country = "Nepal";
    s2.stuAddress.state = "Province 3";
    s2.stuAddress.city = "Kathmandu";
    s2.stuAddress.street  = 33;

    printf("Student Name is: %s", s2.stu_name);
    printf("\nStudent Id is: %d", s2.stu_id);
    printf("\nStudent Age is: %d", s2.stu_age);
    printf("\nStudent country is: %s", s2.stuAddress.country);
    printf("\nStudent state is: %s", s2.stuAddress.state);
    printf("\nStudent city is: %s", s2.stuAddress.city);
    printf("\nStudent street is: %d", s2.stuAddress.street);

    // assigning initializers in strucutre
    struct StudentData d1 = {.stu_name="hari sharma",.stu_id=33,.stu_age=28};

    printf("Student Name is: %s", d1.stu_name);
    printf("\nStudent Id is: %d", d1.stu_id);
    printf("\nStudent Age is: %d", d1.stu_age);


    return 0;
}
// Note: function needs to be declared before it is called.
void PrintStructure(struct Book book)
{   printf("===========function uing . operator==============\n");
    printf("book name = %s \n",book.book_name);
    printf("book author = %s \n",book.author);
    printf("book id = %d \n",book.book_id);
}

void PrintUsingPointer(struct Book *book)
{   printf("===========using pointer and -> operator ==============\n");
    printf("book name = %s \n",book->book_name);
    printf("book author = %s \n",book->author);
    printf("book id = %d \n",book->book_id);
}

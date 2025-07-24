//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct for Book
struct Book{
    char title[100];
    int id;
    float price;
};

//Struct for Index
struct Index{
    int id;
    int location;
};

//Global Variables
struct Book book_arr[100];
struct Index index_arr[100];
int top=0,top_index=0;

//Function to Add a Book
void addBook(char title[],int id,float price){
    struct Book book;
    strcpy(book.title,title);
    book.id=id;
    book.price=price;
    book_arr[top++]=book;

    struct Index index;
    index.id=id;
    index.location=top-1;
    index_arr[top_index++]=index;
}

//Function to Find a Book by ID
void findBook(int id){
    for(int i=0;i<top_index;i++){
        if(index_arr[i].id==id){
            printf("Book Found:\nTitle: %s\nID: %d\nPrice: %f\n\n",book_arr[index_arr[i].location].title,book_arr[index_arr[i].location].id,book_arr[index_arr[i].location].price);
            return;
        }
    }
    printf("Book with ID: %d not found!\n",id);
}

//Function to Delete a Book by ID
void deleteBook(int id){
    for(int i=0;i<top_index;i++){
        if(index_arr[i].id==id){
            for(int j=index_arr[i].location;j<top-1;j++){
                book_arr[j]=book_arr[j+1];
            }
            top--;

            for(int j=i;j<top_index-1;j++){
                index_arr[j]=index_arr[j+1];
            }
            top_index--;
            printf("Book with ID: %d Deleted!\n",id);
            return;
        }
    }
    printf("Book with ID: %d not found!\n",id);
}

//Main Function
int main(){
    //Adding Books
    addBook("Book 1",1,10.0);
    addBook("Book 2",2,20.0);
    addBook("Book 3",3,30.0);

    //Finding book with ID 2
    findBook(2);

    //Deleting book with ID 3
    deleteBook(3);

    //Finding book with ID 3 after deleting
    findBook(3);

    return 0;
}
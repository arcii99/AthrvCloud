//FormAI DATASET v1.0 Category: Ebook reader ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOKS 5
#define MAX_NAME_LENGTH 30
#define MAX_PAGES 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    int pages;
    float size;
    char author[MAX_NAME_LENGTH];
} Book;

void display_menu(){
    printf("\n\n");
    printf("1. Display available books\n");
    printf("2. Read a book\n");
    printf("3. Quit\n");
    printf("\n\n");
}

void display_books(Book books[], int num_books){
    int i;
    printf("\nAvailable Books: \n\n");
    printf("Book Name\tAuthor\tPages\tSize(MB)\n");
    for(i=0;i<num_books;i++){
        printf("%s\t%s\t%d\t%.2f\n",books[i].name,books[i].author,books[i].pages,books[i].size);
    }
    printf("\n\n");
}

void read_book(Book book){
    printf("\nReading %s written by %s\n", book.name, book.author);
    printf("Please wait...\n\n");
    /* Code to read book goes here */
}

int main(){
    Book books[MAX_BOOKS];
    int i=0;
    /* Add book entries manually */
    strcpy(books[i].name,"The Alchemist");
    strcpy(books[i].author,"Paulo Coelho");
    books[i].pages=192;
    books[i].size=1.2;
    i++;

    /* Add book entries manually */
    strcpy(books[i].name,"The Da Vinci Code");
    strcpy(books[i].author,"Dan Brown");
    books[i].pages=454;
    books[i].size=2.5;
    i++;

    /* Add book entries manually */
    strcpy(books[i].name,"Harry Potter and the Philosopher's Stone");
    strcpy(books[i].author,"J. K. Rowling");
    books[i].pages=223;
    books[i].size=1.9;
    i++;

    /* Add book entries manually */
    strcpy(books[i].name,"The Fault in Our Stars");
    strcpy(books[i].author,"John Green");
    books[i].pages=313;
    books[i].size=1.7;
    i++;

    /* Add book entries manually */
    strcpy(books[i].name,"To Kill a Mockingbird");
    strcpy(books[i].author,"Harper Lee");
    books[i].pages=281;
    books[i].size=1.6;
    i++;

    int choice=-1;
    while(choice!=3){
        display_menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display_books(books,i);
                break;
            case 2:
                printf("\nEnter the name of the book you want to read: ");
                char book_name[MAX_NAME_LENGTH];
                scanf("%s",book_name);
                int found=0;
                for(int j=0;j<i;j++){
                    if(strcmp(book_name,books[j].name)==0){
                        read_book(books[j]);
                        found=1;
                        break;
                    }
                }
                if(found==0){
                    printf("\nBook not found!\n");
                }
                break;
            case 3:
                printf("\nQuitting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
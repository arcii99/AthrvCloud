//FormAI DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>
typedef struct{
    char title[50];
    char author[50];
    char publisher[50];
    int year;
}Book;

void display(Book b){
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Publisher: %s\n", b.publisher);
    printf("Year: %d\n", b.year);
}

int main(){
    Book book1;
    strcpy(book1.title, "The Great Gatsby");
    strcpy(book1.author, "F. Scott Fitzgerald");
    strcpy(book1.publisher, "Charles Scribner's Sons");
    book1.year = 1925;

    Book book2;
    strcpy(book2.title, "To Kill a Mockingbird");
    strcpy(book2.author, "Harper Lee");
    strcpy(book2.publisher, "J. B. Lippincott & Co.");
    book2.year = 1960;

    display(book1);
    display(book2);

    return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book{
    char title[100];
    char author[100];
    char genre[50];
    char isbn[14];
    char path[200];
};

int main(){
    struct book love_book;
    strcpy(love_book.title, "The Notebook");
    strcpy(love_book.author, "Nicholas Sparks");
    strcpy(love_book.genre, "Romance");
    strcpy(love_book.isbn, "ISBN-1234567890");
    strcpy(love_book.path, "/ebooks/thenotebook.epub");

    //Display book details
    printf("Title: %s\n", love_book.title);
    printf("Author: %s\n", love_book.author);
    printf("Genre: %s\n", love_book.genre);
    printf("ISBN: %s\n", love_book.isbn);

    //Open book
    FILE *fp = fopen(love_book.path, "rb");
    if(fp == NULL) {
        printf("Sorry, cannot open the book\n");
    } else {
        //Read book content
        fseek(fp, 0L, SEEK_END);
        int size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);

        char *content = (char*) malloc(size * sizeof(char));
        fread(content, sizeof(char), size, fp);

        printf("Book Content:\n%s\n", content);

        free(content);
        fclose(fp);
    }

    return 0;
}
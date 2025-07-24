//FormAI DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ebook {
    char title[50];
    char author[50];
    int year;
    char format[10];
};

typedef struct Ebook Ebook;

void printEbook(Ebook book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
    printf("Format: %s\n", book.format);
}

Ebook* findEbook(Ebook* collection, int collectionSize, const char* title) {
    for(int i=0; i<collectionSize; i++) {
        if(strcmp(collection[i].title, title) == 0) {
            return &collection[i];
        }
    }
    return NULL;
}

int main(void) {
    Ebook collection[5];
    strcpy(collection[0].title, "The Art of Computer Programming");
    strcpy(collection[0].author, "Donald Knuth");
    collection[0].year = 1968;
    strcpy(collection[0].format, "PDF");

    strcpy(collection[1].title, "Cracking the Coding Interview");
    strcpy(collection[1].author, "Gayle McDowell");
    collection[1].year = 2011;
    strcpy(collection[1].format, "MOBI");

    strcpy(collection[2].title, "Clean Code");
    strcpy(collection[2].author, "Robert C. Martin");
    collection[2].year = 2008;
    strcpy(collection[2].format, "EPUB");

    strcpy(collection[3].title, "The Pragmatic Programmer");
    strcpy(collection[3].author, "Andrew Hunt and David Thomas");
    collection[3].year = 1999;
    strcpy(collection[3].format, "PDF");

    strcpy(collection[4].title, "Effective Java");
    strcpy(collection[4].author, "Joshua Bloch");
    collection[4].year = 2001;
    strcpy(collection[4].format, "PDF");

    printf("--- Welcome to the Ebook Reader ---\n");
    printf("Total books in collection: %d\n", sizeof(collection)/sizeof(Ebook));

    Ebook* book = NULL;
    char searchTitle[50];
    printf("\nEnter the title of the book to search: ");
    scanf("%s", searchTitle);
    book = findEbook(collection, sizeof(collection)/sizeof(Ebook), searchTitle);
    if (book != NULL) {
        printf("\nBook found in collection!\n");
        printEbook(*book);
    } else {
        printf("\nBook not found in collection!\n");
    }

    return EXIT_SUCCESS;
}
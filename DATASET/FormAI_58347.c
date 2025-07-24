//FormAI DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int pages;
    char *filename;
} Ebook;

void readEbook(Ebook *book) {
    printf("Enter the title of the ebook: ");
    scanf("%s", book->title);
    printf("Enter the author of the ebook: ");
    scanf("%s", book->author);
    printf("Enter the number of pages in the ebook: ");
    scanf("%d", &book->pages);
    printf("Enter the filename of the ebook: ");
    scanf("%s", book->filename);
}

void printEbook(Ebook book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Pages: %d\n", book.pages);
    printf("Filename: %s\n", book.filename);
}

int main() {
    Ebook my_book;
    my_book.title = malloc(sizeof(char) * 100);
    my_book.author = malloc(sizeof(char) * 100);
    my_book.filename = malloc(sizeof(char) * 100);

    readEbook(&my_book);
    printf("Ebook details: \n");
    printEbook(my_book);

    free(my_book.title);
    free(my_book.author);
    free(my_book.filename);
    
    return 0;
}
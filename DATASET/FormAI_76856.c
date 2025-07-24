//FormAI DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char title[50];
    char author[50];
    char filepath[100];
} Book;

typedef struct {
    Book *books;
    int size;
} Catalogue;

void read_books(Catalogue *catalogue) {
    FILE *fp;
    fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp)) {
        Book *book = (Book*) malloc(sizeof(Book));
        sscanf(buffer, "%d,%[^,],%[^,],%[^\n]", &book->id, book->title, book->author, book->filepath);
        catalogue->books[catalogue->size++] = *book;
    }
    fclose(fp);
}

int main() {
    Catalogue catalogue;
    catalogue.books = (Book*) malloc(sizeof(Book) * 10);
    catalogue.size = 0;
    read_books(&catalogue);
    printf("Catalogue loaded with %d books\n", catalogue.size);
    // code to display ebook reader interface
    return 0;
}
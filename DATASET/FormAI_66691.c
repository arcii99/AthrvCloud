//FormAI DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int year;
} book;

int main() {
    int num_of_books;
    printf("Enter the number of books: ");
    scanf("%d", &num_of_books);

    book *library = (book*) malloc(num_of_books * sizeof(book));
    if (library == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_of_books; i++) {
        printf("\nBOOK %d\n", i+1);
        printf("Enter title: ");
        scanf(" %[^\n]s", library[i].title);
        printf("Enter author: ");
        scanf(" %[^\n]s", library[i].author);
        printf("Enter year: ");
        scanf("%d", &library[i].year);
    }

    printf("\n*** Ebook Library ***\n");
    for (int i = 0; i < num_of_books; i++) {
        printf("\nBOOK %d\n", i+1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
    }

    free(library);
    return 0;
}
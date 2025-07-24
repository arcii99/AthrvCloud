//FormAI DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
   char title[50];
   char author[50];
   char category[50];
   int year_published;
};

void display_book(struct book bk) {
    printf("Title: %s\n", bk.title);
    printf("Author: %s\n", bk.author);
    printf("Category: %s\n", bk.category);
    printf("Year Published: %d\n", bk.year_published);
}

int main() {
    int num_books;
    printf("Enter the number of books in your library: ");
    scanf("%d", &num_books);

    struct book library[num_books]; 

    for (int i = 0; i < num_books; i++) {
        printf("Enter details for book #%d:\n", i+1);
        printf("Title: ");
        scanf(" %[^\n]s", library[i].title);
        printf("Author: ");
        scanf(" %[^\n]s", library[i].author);
        printf("Category: ");
        scanf(" %[^\n]s", library[i].category);
        printf("Year Published: ");
        scanf("%d", &library[i].year_published);
    }

    printf("Library Catalog:\n");
    for (int i = 0; i < num_books; i++) {
        display_book(library[i]);
    }

    return 0;
}
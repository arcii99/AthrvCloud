//FormAI DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book {
    char title[50];
    char author[30];
    int year;
    double price;
} Book;

int main() {
    // Using dynamic memory allocation for flexible number of books
    int num_books;
    printf("Enter the number of books: ");
    scanf("%d", &num_books);
    Book *books = malloc(num_books * sizeof(Book));

    // Filling up the book info
    for (int i = 0; i < num_books; i++) {
        printf("\n=== Book %d ===\n", i+1);
        printf("Title: ");
        scanf(" %[^\n]s", books[i].title);
        printf("Author: ");
        scanf(" %[^\n]s", books[i].author);
        printf("Year of publication: ");
        scanf("%d", &books[i].year);
        printf("Price: ");
        scanf("%lf", &books[i].price);
    }

    // Displaying the books
    printf("\n\n=== All Books ===\n");
    for (int i = 0; i < num_books; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year of publication: %d\n", books[i].year);
        printf("Price: %.2f\n", books[i].price);
        printf("\n");
    }

    free(books);
    return 0;
}
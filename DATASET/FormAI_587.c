//FormAI DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 20
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 25

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    float price;
} Book;

void print_book(Book b) {
    printf("\nTitle: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
    printf("Price: $%.2f\n", b.price);
}

int main() {
    int num_books = 0;
    Book library[MAX_BOOKS];
    char choice;

    printf("*** EBook Reader ***\n\n");

    do {
        printf("Choose an option:\n");
        printf("1. Add a book\n");
        printf("2. View all books\n");
        printf("3. Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (num_books < MAX_BOOKS) {
                    printf("\nEnter book title: ");
                    scanf(" %[^\n]s", library[num_books].title);
                    printf("Enter book author: ");
                    scanf(" %[^\n]s", library[num_books].author);
                    printf("Enter number of pages: ");
                    scanf("%d", &library[num_books].pages);
                    printf("Enter price: $");
                    scanf("%f", &library[num_books].price);
                    num_books++;
                    printf("\nBook added!\n");
                } else {
                    printf("\nThe library is full.\n");
                }
                break;
            case '2':
                if (num_books > 0) {
                    printf("\nLibrary contents:\n");
                    for (int i = 0; i < num_books; i++) {
                        print_book(library[i]);
                    }
                } else {
                    printf("\nThe library is empty.\n");
                }
                break;
            case '3':
                printf("\nThank you for using EBook Reader.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice != '3');

    return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_PAGES 500

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
};

void read_book(struct Book *book) {
    printf("Please enter the title of the book: ");
    fgets(book->title, MAX_TITLE_LENGTH, stdin);
    book->title[strcspn(book->title, "\n")] = '\0';

    printf("Please enter the author of the book: ");
    fgets(book->author, MAX_AUTHOR_LENGTH, stdin);
    book->author[strcspn(book->author, "\n")] = '\0';

    printf("Please enter the number of pages in the book: ");
    scanf("%d", &book->pages);
    getchar(); // consume the \n left in the buffer after scanf
}

void print_book(struct Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Pages: %d\n", book->pages);
}

int main() {
    struct Book my_book = {"The Hound of the Baskervilles", "Arthur Conan Doyle", 256};
    printf("The program has initialized a book: \n");
    print_book(&my_book);

    printf("\nNow you can enter your own book details: \n");
    read_book(&my_book);
    printf("\nYour book details are as follows: \n");
    print_book(&my_book);

    return 0;
}
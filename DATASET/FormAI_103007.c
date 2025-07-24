//FormAI DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* title;
    char* author;
    int num_pages;
    int curr_page;
} Ebook;

void read_book(Ebook* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Total number of pages: %d\n", book->num_pages);
    printf("Current page: %d\n", book->curr_page);
}

void turn_page(Ebook* book) {
    if (book->curr_page < book->num_pages) {
        book->curr_page++;
        printf("Page turned. Current page: %d\n", book->curr_page);
    } else {
        printf("You have reached the end of the book.\n");
    }
}

int main() {
    Ebook* my_book = (Ebook*) malloc(sizeof(Ebook));
    my_book->title = "The C Programming Language";
    my_book->author = "Brian Kernighan and Dennis Ritchie";
    my_book->num_pages = 272;
    my_book->curr_page = 1;

    read_book(my_book);

    turn_page(my_book);
    turn_page(my_book);
    turn_page(my_book);

    free(my_book);
    return 0;
}
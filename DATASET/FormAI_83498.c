//FormAI DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[100];
    char author[100];
    int pages;
    char *content;
};

struct bookshelf {
    struct book *books;
    int num_books;
};

int main() {
    struct bookshelf shelf;
    shelf.num_books = 0;
    shelf.books = NULL;

    // initial bookshelf setup code goes here

    while (1) {
        // main UI loop code goes here
    }

    return 0;
}
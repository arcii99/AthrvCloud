//FormAI DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* bookTitle;
    char* authorName;
    int numOfPages;
} Ebook;

void printEbookInfo(Ebook* book) {
    printf("Title: %s\n", book->bookTitle);
    printf("Author: %s\n", book->authorName);
    printf("Number of Pages: %d\n", book->numOfPages);
}

int main() {
    Ebook myBook;
    myBook.bookTitle = "The C Programming Language";
    myBook.authorName = "Brian W. Kernighan & Dennis M. Ritchie";
    myBook.numOfPages = 274;

    printEbookInfo(&myBook);

    return 0;
}
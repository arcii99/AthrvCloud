//FormAI DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[100];
    char author[50];
    float price;
    int pages;
};

int main() {
    struct book myBook;
    FILE *fptr;

    fptr = fopen("book.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    printf("Title:\t\t\tAuthor:\t\t\tPrice:\tPages:\n");

    while (fscanf(fptr, "%s %s %f %d", myBook.title, myBook.author, &myBook.price, &myBook.pages) != EOF) {
        printf("%-20s\t%-20s\t$%.2f\t%d\n", myBook.title, myBook.author, myBook.price, myBook.pages);
    }

    fclose(fptr);

    return 0;
}
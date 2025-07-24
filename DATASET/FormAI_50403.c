//FormAI DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

int main() {
    struct book my_book;
    
    printf("Enter book details:\n");
    printf("Title: ");
    fgets(my_book.title, 50, stdin);
    printf("Author: ");
    fgets(my_book.author, 50, stdin);
    printf("Number of pages: ");
    scanf("%d", &my_book.pages);
    printf("Price: ");
    scanf("%f", &my_book.price);

    printf("\nBook Details:\n");
    printf("Title: %s", my_book.title);
    printf("Author: %s", my_book.author);
    printf("Number of pages: %d\n", my_book.pages);
    printf("Price: $%.2f\n", my_book.price);

    return 0;
}
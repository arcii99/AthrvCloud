//FormAI DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a structure for book data
struct ebook {
    char title[100];
    char author[100];
    int year;
    float price;
    char filetype[10];
};

// Function to read and display the book data
void readEbook(struct ebook book) {
    printf("\nBook Title: %s", book.title);
    printf("\nAuthor: %s", book.author);
    printf("\nYear Published: %d", book.year);
    printf("\nPrice: %.2f", book.price);
    printf("\nFile Type: %s\n", book.filetype);
}

int main(){
    // Creating an ebook object
    struct ebook book1;

    // Reading the book data from the user
    printf("Enter Book Title: ");
    fgets(book1.title, 100, stdin);
    printf("Enter Author: ");
    fgets(book1.author, 100, stdin);
    printf("Enter Year of Publication: ");
    scanf("%d", &book1.year);
    printf("Enter Price: ");
    scanf("%f", &book1.price);
    printf("Enter File Type: ");
    fgets(book1.filetype, 10, stdin);

    // Displaying the book information
    readEbook(book1);

    return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Welcome message
    printf("Welcome to the Futuristic E-book Reader Program!\n");

    // Variables to hold book data
    char title[50];
    char author[50];
    int pages;
    float price;

    // User input
    printf("Please enter the title of the book: ");
    fgets(title, 50, stdin); // Use fgets to handle spaces
    printf("Please enter the author of the book: ");
    fgets(author, 50, stdin);
    printf("Please enter the number of pages: ");
    scanf("%d", &pages);
    printf("Please enter the price of the book: ");
    scanf("%f", &price);

    // Book display
    printf("\nTitle: %s", title);
    printf("Author: %s", author);
    printf("Number of Pages: %d\n", pages);
    printf("Price: $%.2f\n", price);

    // End message
    printf("\nThank you for using the Futuristic E-book Reader Program!");

    return 0;
}
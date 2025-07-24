//FormAI DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold details of an ebook
typedef struct ebook {
    char title[50];
    char author[50];
    int pages;
    char content[10000];
} Ebook;

// Function to display the details of an ebook
void display_ebook(Ebook book) {
    printf("\nTitle: %s\nAuthor: %s\nPages: %d\n\n%s", book.title, book.author, book.pages, book.content);
}

int main() {
    // Create an instance of an ebook with hardcoded values
    Ebook my_book;
    strcpy(my_book.title, "The Chronicles of Narnia");
    strcpy(my_book.author, "C.S. Lewis");
    my_book.pages = 100;
    strcpy(my_book.content, "Once upon a time, there were four children whose names were Peter, Susan, Edmund, and Lucy...");

    // Display the ebook title
    printf("Welcome to the Medieval Ebook Reader\n");
    printf("===================================\n");
    printf("Title: %s\n", my_book.title);

    // Prompt user to view the ebook contents
    printf("Do you want to read the book? (y/n)\n");
    char response = getchar();

    // If user selects 'y', display the ebook details
    if (response == 'y') {
        display_ebook(my_book);
    }
    
    // Exit the program
    return 0;
}
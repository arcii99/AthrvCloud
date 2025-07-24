//FormAI DATASET v1.0 Category: Ebook reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of pages a book can have
#define MAX_PAGES 1000

// Define the Ebook structure
struct Ebook {
    char title[100];
    char author[50];
    int num_pages;
    char contents[MAX_PAGES][1000];
};

// Function to open a book
void openBook(struct Ebook *book) {
    // Print the title and author of the book
    printf("Opening Book:\n");
    printf("%s by %s\n\n", book->title, book->author);

    // Print the table of contents
    printf("Table of Contents\n");
    for (int i = 0; i < book->num_pages; i++) {
        printf("%d. %s\n", i+1, book->contents[i]);
    }
    printf("\n");

    // Ask the user which page they want to read
    int pageNum;
    printf("Enter page number to read (1-%d): ", book->num_pages);
    scanf("%d", &pageNum);

    // Check if the page number is valid
    if (pageNum < 1 || pageNum > book->num_pages) {
        printf("Invalid page number.\n");
    } else {
        // Print the contents of the selected page
        printf("\n%s\n\n", book->contents[pageNum-1]);
    }
}

int main() {
    // Create an Ebook
    struct Ebook myBook;
    strcpy(myBook.title, "The Adventures of Tom Sawyer");
    strcpy(myBook.author, "Mark Twain");
    myBook.num_pages = 5;
    strcpy(myBook.contents[0], "Chapter 1: Introduction");
    strcpy(myBook.contents[1], "Chapter 2: Tom's First Love");
    strcpy(myBook.contents[2], "Chapter 3: Treasure Hunt");
    strcpy(myBook.contents[3], "Chapter 4: Becky Thatcher");
    strcpy(myBook.contents[4], "Chapter 5: Injun Joe");

    // Open the Ebook
    openBook(&myBook);

    // Exit the program
    return 0;
}
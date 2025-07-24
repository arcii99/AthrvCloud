//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 100 // Change this to increase the maximum number of pages

typedef struct {
    char *title;
    char *content;
} Page;

typedef struct {
    Page pages[MAX_PAGES];
    int current_page;
    int num_pages;
} Ebook;

// Function to display the current page of the Ebook
void display_page(Ebook *book) {
    printf("%s\n\n", book->pages[book->current_page].title);
    printf("%s\n", book->pages[book->current_page].content);
}

// Function to add a new page to the Ebook
void add_page(Ebook *book, char *title, char *content) {
    if (book->num_pages >= MAX_PAGES) {
        printf("Cannot add page: Ebook is full\n");
        return;
    }
    book->pages[book->num_pages].title = strdup(title);
    book->pages[book->num_pages].content = strdup(content);
    book->num_pages++;
}

// Function to navigate to the next page of the Ebook
void next_page(Ebook *book) {
    if (book->current_page < book->num_pages - 1) {
        book->current_page++;
        display_page(book);
    } else {
        printf("Cannot go to next page: Already at last page\n");
    }
}

// Function to navigate to the previous page of the Ebook
void prev_page(Ebook *book) {
    if (book->current_page > 0) {
        book->current_page--;
        display_page(book);
    } else {
        printf("Cannot go to previous page: Already at first page\n");
    }
}

// Main function to run the Ebook reader
int main() {
    Ebook book;
    book.current_page = 0;
    book.num_pages = 0;

    add_page(&book, "Chapter 1", "Once upon a time...");
    add_page(&book, "Chapter 2", "And they lived happily ever after.");

    display_page(&book);

    char command[10];
    while (1) {
        printf("Enter a command (next, prev, exit): ");
        scanf("%s", command);

        if (strcmp(command, "next") == 0) {
            next_page(&book);
        } else if (strcmp(command, "prev") == 0) {
            prev_page(&book);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Ebook reader\n");
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
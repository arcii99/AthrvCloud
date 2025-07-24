//FormAI DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BOOKS 20
#define MAX_TITLE_SIZE 50
#define MAX_AUTHOR_SIZE 25
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    int num_pages;
    bool is_favorite;
} Ebook;

// Array to store all the books
Ebook library[MAX_BOOKS];

// Function to add books to the library
void add_book(char* title, char* author, int num_pages, bool is_favorite) {
    Ebook book;
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.num_pages = num_pages;
    book.is_favorite = is_favorite;
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (strlen(library[i].title) == 0) {
            library[i] = book;
            printf("Book added to library.\n");
            return;
        }
    }
    printf("Library is full, cannot add book.\n");
}

// Function to remove books from the library
void remove_book(int index) {
    if (strlen(library[index].title) == 0) {
        printf("No book found at index %d.\n", index);
    } else {
        library[index] = (Ebook) {0};
        printf("Book at index %d removed from library.\n", index);
    }
}

// Function to display all the books in the library
void display_library() {
    printf("Library Contents:\n");
    for (int i = 0; i < MAX_BOOKS; i++) {
        if (strlen(library[i].title) != 0) {
            printf("Index %d: \"%s\" by %s, %d pages, ", i, library[i].title, library[i].author, library[i].num_pages);
            if (library[i].is_favorite) {
                printf("favorite.\n");
            } else {
                printf("not favorite.\n");
            }
        }
    }
}

// Function to display a specific book in the library
void display_book(int index) {
    if (strlen(library[index].title) == 0) {
        printf("No book found at index %d.\n", index);
    } else {
        printf("Book Details:\n");
        printf("Title: %s\n", library[index].title);
        printf("Author: %s\n", library[index].author);
        printf("Number of pages: %d\n", library[index].num_pages);
        if (library[index].is_favorite) {
            printf("Favorite book.\n");
        } else {
            printf("Not a favorite book.\n");
        }
    }
}

// Function to read an ebook asynchronously (imagine this takes time)
void read_ebook_async(int index) {
    printf("Starting to read \"%s\"...\n", library[index].title);
    srand(time(NULL));
    int time_spent = (rand() % 11) * 10;  // Random time from 0-100 seconds
    printf("%d seconds have passed.\n", time_spent);
    printf("Finished reading \"%s\".\n", library[index].title);
}

int main() {
    // Add some books to the library
    add_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 224, true);
    add_book("1984", "George Orwell", 328, false);
    add_book("The Lord of the Rings", "J.R.R. Tolkien", 1178, true);

    // Display the library
    printf("\n");
    display_library();

    // Display a specific book
    printf("\n");
    display_book(1);

    // Remove a book from the library
    printf("\n");
    remove_book(1);

    // Display the library again
    printf("\n");
    display_library();

    // Read a book asynchronously
    printf("\n");
    read_ebook_async(0);

    return 0;
}
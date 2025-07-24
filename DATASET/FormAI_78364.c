//FormAI DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    char file_name[50];
};

struct BookLibrary {
    struct Book books[MAX_BOOKS];
    int num_books;
};

void add_book(struct BookLibrary *library, char *title, char *author, char *file_name);
void display_library(struct BookLibrary *library);
void read_book(char *file_name);

int main() {
    struct BookLibrary library;
    library.num_books = 0;

    // Add some books to the library
    add_book(&library, "The Art of War", "Sun Tzu", "the_art_of_war.txt");
    add_book(&library, "Pride and Prejudice", "Jane Austen", "pride_and_prejudice.txt");
    add_book(&library, "The Catcher in the Rye", "J.D. Salinger", "the_catcher_in_the_rye.txt");

    // Display the library
    display_library(&library);

    // Read a book
    read_book("the_art_of_war.txt");

    return 0;
}

void add_book(struct BookLibrary *library, char *title, char *author, char *file_name) {
    if (library->num_books >= MAX_BOOKS) {
        printf("Library is full. Cannot add book.\n");
        return;
    }

    struct Book new_book;
    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    strcpy(new_book.file_name, file_name);

    library->books[library->num_books] = new_book;
    library->num_books++;

    printf("Book added to library: %s by %s\n", title, author);
}

void display_library(struct BookLibrary *library) {
    printf("Book Library\n");
    printf("-------------\n");
    for (int i = 0; i < library->num_books; i++) {
        printf("%s, by %s (filename: %s)\n", library->books[i].title, library->books[i].author, library->books[i].file_name);
    }
}

void read_book(char *file_name) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", file_name);
        return;
    }

    printf("\nReading book: %s\n", file_name);

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
}
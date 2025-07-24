//FormAI DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50
#define MAX_AUTHOR 50
#define MAX_PAGES 5000

// Define the Book struct
typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int pages;
    char* contents;
} Book;

// Define the EbookReader struct
typedef struct {
    int num_books;
    Book books[MAX_BOOKS];
} EbookReader;

// Function to add a book to the EbookReader
void addBook(EbookReader* reader, char* title, char* author, int pages, char* contents) {
    if (reader->num_books == MAX_BOOKS) {
        printf("Error: EbookReader is full!\n");
        return;
    }
    Book newBook;
    strncpy(newBook.title, title, MAX_TITLE - 1);
    strncpy(newBook.author, author, MAX_AUTHOR - 1);
    newBook.pages = pages;
    newBook.contents = malloc(sizeof(char) * MAX_PAGES);
    strncpy(newBook.contents, contents, MAX_PAGES - 1);
    reader->books[reader->num_books] = newBook;
    reader->num_books++;
    printf("Book added to EbookReader!\n");
}

// Function to remove a book from the EbookReader 
void removeBook(EbookReader* reader, char* title) {
    int index = -1;
    for (int i = 0; i < reader->num_books; i++) {
        if (strcmp(reader->books[i].title, title) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Book not found!\n");
        return;
    }
    free(reader->books[index].contents);
    for (int i = index; i < reader->num_books - 1; i++) {
        reader->books[i] = reader->books[i + 1];
    }
    reader->num_books--;
    printf("Book removed from EbookReader!\n");
}

// Function to print the contents of a book
void readBook(EbookReader* reader, char* title) {
    int index = -1;
    for (int i = 0; i < reader->num_books; i++) {
        if (strcmp(reader->books[i].title, title) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Book not found!\n");
        return;
    }
    printf("%s\n", reader->books[index].contents);
}

int main() {
    EbookReader reader;
    reader.num_books = 0;

    // Add a book to the EbookReader
    addBook(&reader, "Jane Eyre", "Charlotte Bronte", 500, "It was a bright cold day in April, and the clocks were striking thirteen. ");
    
    // Read a book from the EbookReader
    readBook(&reader, "Jane Eyre");
    
    // Remove a book from the EbookReader
    removeBook(&reader, "Jane Eyre");

    return 0;
}
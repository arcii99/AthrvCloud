//FormAI DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of books the reader can hold
#define MAX_BOOKS 10

// Define the structure for a book
struct Book {
    char title[50];
    char author[50];
    int year;
    char genre[20];
};

// Define the structure for the ebook reader
struct EbookReader {
    struct Book library[MAX_BOOKS];
    int num_books;
};

// Function to add books to the reader's library
void add_book(struct EbookReader *reader, char *title, char *author, int year, char *genre) {
    if (reader->num_books < MAX_BOOKS) {
        struct Book new_book;
        strcpy(new_book.title, title);
        strcpy(new_book.author, author);
        new_book.year = year;
        strcpy(new_book.genre, genre);
        reader->library[reader->num_books] = new_book;
        reader->num_books++;
        printf("Book added to library: %s\n", title);
    } else {
        printf("Library is full!\n");
    }
}

// Function to print all books in the reader's library
void print_library(struct EbookReader *reader) {
    printf("Library contents:\n");
    for (int i = 0; i < reader->num_books; i++) {
        printf("%d. %s\n", i+1, reader->library[i].title);
        printf("   Author: %s\n", reader->library[i].author);
        printf("   Year: %d\n", reader->library[i].year);
        printf("   Genre: %s\n", reader->library[i].genre);
    }
}

// Main function
int main() {
    // Initialize the ebook reader
    struct EbookReader reader;
    reader.num_books = 0;

    // Add some books to the library
    add_book(&reader, "The Lord of the Rings", "J.R.R. Tolkien", 1954, "Fantasy");
    add_book(&reader, "To Kill a Mockingbird", "Harper Lee", 1960, "Classic");
    add_book(&reader, "1984", "George Orwell", 1949, "Dystopian");

    // Print the contents of the library
    print_library(&reader);

    return 0;
}
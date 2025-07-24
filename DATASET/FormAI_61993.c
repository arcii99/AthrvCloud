//FormAI DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_TITLE_LENGTH];
    int year;
    double price;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int numBooks;
} EbookReader;

void initializeReader(EbookReader* reader) {
    reader->numBooks = 0;
}

int addBookToReader(EbookReader* reader, char* title, char* author, int year, double price) {
    if (reader->numBooks >= MAX_BOOKS) {
        return 0;
    }
    
    Book newBook;
    strncpy(newBook.title, title, MAX_TITLE_LENGTH);
    strncpy(newBook.author, author, MAX_TITLE_LENGTH);
    newBook.year = year;
    newBook.price = price;
    reader->books[reader->numBooks] = newBook;
    reader->numBooks++;
    return 1;
}

void printListOfBooks(EbookReader reader) {
    if (reader.numBooks == 0) {
        printf("No books in reader.\n");
        return;
    }
    for (int i = 0; i < reader.numBooks; i++) {
        printf("%d. %s by %s (%d) - $%.2f\n", i+1, reader.books[i].title, reader.books[i].author, 
               reader.books[i].year, reader.books[i].price);
    }
}

int main() {
    EbookReader reader;
    initializeReader(&reader);
    
    addBookToReader(&reader, "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979, 7.99);
    addBookToReader(&reader, "1984", "George Orwell", 1949, 9.99);
    addBookToReader(&reader, "The Lord of the Rings", "J.R.R. Tolkien", 1954, 14.99);
    
    printf("List of books in reader:\n");
    printListOfBooks(reader);
    
    return 0;
}
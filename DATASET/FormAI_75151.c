//FormAI DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 10 // Maximum number of books that can be stored

struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

struct Ebook_Reader {
    int num_books;
    struct Book books[MAX_BOOKS];
};

// Function to add a book to the ebook reader
void addBook(struct Ebook_Reader *reader, char title[], char author[], int pages, float price) {
    // Check if the reader has already reached the maximum number of books
    if (reader->num_books >= MAX_BOOKS) {
        printf("Error: The ebook reader already has the maximum number of books.\n");
        return;
    }
    
    // Add the book to the reader
    struct Book new_book;
    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    new_book.pages = pages;
    new_book.price = price;
    
    reader->books[reader->num_books] = new_book;
    reader->num_books++;
}

// Function to display all books in the ebook reader
void displayBooks(struct Ebook_Reader *reader) {
    printf("Books in the ebook reader:\n");
    for (int i = 0; i < reader->num_books; i++) {
        printf("Title: %s\n", reader->books[i].title);
        printf("Author: %s\n", reader->books[i].author);
        printf("Pages: %d\n", reader->books[i].pages);
        printf("Price: %.2f\n\n", reader->books[i].price);
    }
}

int main() {
    // Create a new ebook reader
    struct Ebook_Reader my_reader = {0};
    
    // Add some books
    addBook(&my_reader, "The Catcher in the Rye", "J.D. Salinger", 224, 7.99);
    addBook(&my_reader, "To Kill a Mockingbird", "Harper Lee", 281, 9.99);
    addBook(&my_reader, "Nineteen Eighty-Four", "George Orwell", 328, 6.99);
    
    // Display all books
    displayBooks(&my_reader);
    
    return 0;
}
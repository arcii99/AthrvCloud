//FormAI DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Book {
    char title[50];
    char author[50];
    int pages;
    char file_name[50];
} Book;

bool is_valid_file(Book book) {
    char extension[] = ".pdf";
    int title_len = strlen(book.title);
    int extension_len = strlen(extension);
    int file_name_len = strlen(book.file_name);
    return file_name_len == title_len + extension_len && 
           strstr(book.file_name, extension) != NULL && 
           strncmp(book.title, book.file_name, title_len) == 0;
}

void read_book(Book book) {
    printf("Opening %s...\n", book.title);
    if (!is_valid_file(book)) {
        printf("Invalid file name for %s.\n", book.title);
        return;
    }
    // Code to actually read book goes here
    printf("Finished reading %s.\n", book.title);
}

int main() {
    Book book1 = {"The Hobbit", "J.R.R. Tolkien", 310, "the_hobbit.pdf"};
    Book book2 = {"1984", "George Orwell", 328, "1984.pdf"};
    Book book3 = {"Pride and Prejudice", "Jane Austen", 432, "pride_and_prejudice.pdf"};

    read_book(book1);
    read_book(book2);
    read_book(book3);

    return 0;
}
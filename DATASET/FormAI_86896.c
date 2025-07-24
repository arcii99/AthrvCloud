//FormAI DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for books
typedef struct {
    char title[50];
    char author[50];
    int year_published;
} Book;

// function to add book to file
void add_book(Book book) {
    FILE *file = fopen("my_library.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "%s~%s~%d\n", book.title, book.author, book.year_published);
    fclose(file);
}

// function to display all books in file
void display_books() {
    FILE *file = fopen("my_library.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("Title~Author~Year Published\n");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char* title = strtok(line, "~");
        char* author = strtok(NULL, "~");
        char* year_published_string = strtok(NULL, "~");
        int year_published = atoi(year_published_string);
        printf("%s~%s~%d\n", title, author, year_published);
    }
    fclose(file);
}

int main() {
    // create books
    Book book1, book2, book3;
    strcpy(book1.title, "The Catcher in the Rye");
    strcpy(book1.author, "J.D. Salinger");
    book1.year_published = 1951;
    strcpy(book2.title, "To Kill a Mockingbird");
    strcpy(book2.author, "Harper Lee");
    book2.year_published = 1960;
    strcpy(book3.title, "1984");
    strcpy(book3.author, "George Orwell");
    book3.year_published = 1949;

    // add books to file
    add_book(book1);
    add_book(book2);
    add_book(book3);

    // display all books in file
    display_books();

    return 0;
}
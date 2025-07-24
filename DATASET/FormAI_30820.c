//FormAI DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
} Ebook;

typedef struct {
    Ebook collection[MAX_BOOKS];
    int num_books;
} EbookLibrary;

void add_book(EbookLibrary *library, Ebook book) {
    if (library->num_books >= MAX_BOOKS) {
        printf("Error: Library can't hold more than %d books.\n", MAX_BOOKS);
        return;
    }

    library->collection[library->num_books] = book;
    library->num_books++;
}

void display_books(EbookLibrary *library) {
    printf("\nNumber of books in library: %d\n", library->num_books);

    for (int i = 0; i < library->num_books; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", library->collection[i].title);
        printf("Author: %s\n", library->collection[i].author);
        printf("File name: %s\n", library->collection[i].file_name);
    }
}

void read_ebook(char *file_name) {
    printf("\nReading ebook file: %s\n", file_name);
    // Code to read ebook goes here
}

int main() {
    EbookLibrary my_library = {0};

    Ebook book1 = {"The Art of Computer Programming", "Donald Knuth", "art_of_computer_programming.pdf"};
    Ebook book2 = {"Structure and Interpretation of Computer Programs", "Harold Abelson and Gerald Jay Sussman", "structure_and_interpretation_of_computer_programs.pdf"};

    add_book(&my_library, book1);
    add_book(&my_library, book2);

    display_books(&my_library);

    read_ebook(my_library.collection[0].file_name);

    return 0;
}
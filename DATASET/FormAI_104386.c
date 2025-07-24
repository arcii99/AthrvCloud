//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char ebook_file_name[100];
} Book;

int main() {
    int num_books = 0;
    Book library[MAX_BOOKS];
    char input[100];
    char selected_book[100];

    // populate library with ebook files
    // omitting code for brevity
    
    // display the list of books in the library
    printf("List of books in the library:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i+1, library[i].title, library[i].author);
    }

    // prompt user to select a book
    printf("\nEnter the number of the book you want to read: ");
    fgets(input, sizeof(input), stdin);
    int selection = atoi(input);
    if (selection <= 0 || selection > num_books) {
        printf("Invalid selection. Exiting.\n");
        return 0;
    }

    // copy over the selected book's filename and open it
    strcpy(selected_book, library[selection-1].ebook_file_name);
    FILE* ebook_file = fopen(selected_book, "r");
    if (ebook_file == NULL) {
        printf("Error: Could not open file %s\n", selected_book);
        return 0;
    }

    // read the ebook contents and print them
    char line[256];
    while (fgets(line, sizeof(line), ebook_file)) {
        printf("%s", line);
    }

    return 0;
}
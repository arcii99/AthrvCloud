//FormAI DATASET v1.0 Category: Ebook reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_PAGES 5000

typedef struct book {
    char title[100];
    char author[100];
    int num_pages;
    char pages[MAX_PAGES][1000];
} Book;

Book library[MAX_BOOKS]; // Global variable to hold books

int num_books = 0; // Global variable to hold number of books in library

void load_book(Book *book, char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[1000];
    int page_num = 0;
    while (fgets(buffer, 1000, file)) {
        if (strlen(buffer) > 1) { // Skip blank lines
            strcpy(book->pages[page_num], buffer);
            page_num++;
        }
    }
    fclose(file);
}

void add_book(char *title, char *author, char *filename) {
    if (num_books >= MAX_BOOKS) {
        printf("Sorry, the library is full!\n");
        return;
    }
    Book *book = &library[num_books];
    strcpy(book->title, title);
    strcpy(book->author, author);
    load_book(book, filename);
    book->num_pages = num_books;
    num_books++;
    printf("Book added to library.\n");
}

void print_page(Book *book, int page_num) {
    printf("%s - %s\n\n", book->title, book->author);
    printf("%s\n", book->pages[page_num]);
}

int main() {
    add_book("Pride and Prejudice", "Jane Austen", "pride_and_prejudice.txt");
    add_book("Wuthering Heights", "Emily Bronte", "wuthering_heights.txt");
    add_book("Jane Eyre", "Charlotte Bronte", "jane_eyre.txt");

    int book_num = 0;
    int page_num = 0;
    char input[10];
    while (1) {
        print_page(&library[book_num], page_num);
        printf("Enter 'n' for next page, 'p' for previous page, 'q' to quit:");
        fgets(input, 10, stdin);
        if (strcmp(input, "n\n") == 0) {
            if (page_num < library[book_num].num_pages - 1) {
                page_num++;
            }
        } else if (strcmp(input, "p\n") == 0) {
            if (page_num > 0) {
                page_num--;
            }
        } else if (strcmp(input, "q\n") == 0) {
            break;
        } else {
            printf("Invalid input! Please enter 'n', 'p', or 'q'.\n");
        }
    }
    printf("Goodbye!\n");

    return 0;
}
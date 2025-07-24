//FormAI DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 1000
#define MAX_PAGE_SIZE 500

typedef struct {
    char page[MAX_PAGE_SIZE];
} EbookPage;

typedef struct {
    EbookPage pages[MAX_PAGES];
    int current_page;
    int num_pages;
    char title[100];
} Ebook;

void display_page(Ebook* book) {
    printf("\n%s - Page %d of %d\n\n", book->title, book->current_page + 1, book->num_pages);
    printf("%s", book->pages[book->current_page].page);
}

void next_page(Ebook* book) {
    if (book->current_page < book->num_pages - 1) {
        book->current_page++;
        display_page(book);
    } else {
        printf("\nEnd of Book\n");
    }
}

void previous_page(Ebook* book) {
    if (book->current_page > 0) {
        book->current_page--;
        display_page(book);
    } else {
        printf("\nBeginning of Book\n");
    }
}

void load_book(Ebook* book, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nError: Could not open file '%s'\n", filename);
        exit(1);
    }
    book->num_pages = 0;
    while (fgets(book->pages[book->num_pages].page, MAX_PAGE_SIZE, fp)) {
        book->num_pages++;
    }
    fclose(fp);
}

int main() {
    Ebook book;
    book.current_page = 0;
    printf("Enter the filename of the ebook to open: ");
    char filename[100];
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;
    load_book(&book, filename);
    strcpy(book.title, strtok(filename, "."));
    display_page(&book);

    char command;
    printf("\nEnter 'n' for next page, 'p' for previous page, or 'q' to quit: ");
    while (1) {
        scanf(" %c", &command);
        if (command == 'n') {
            next_page(&book);
        } else if (command == 'p') {
            previous_page(&book);
        } else if (command == 'q') {
            break;
        } else {
            printf("\nInvalid command. Enter 'n' for next page, 'p' for previous page, or 'q' to quit: ");
        }
    }
    return 0;
}
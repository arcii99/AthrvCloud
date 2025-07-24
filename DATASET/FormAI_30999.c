//FormAI DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 100
#define MAX_LINES_PER_PAGE 20
#define MAX_PAGES_PER_BOOK 100

typedef struct {
    int page_number;
    char lines[MAX_LINES_PER_PAGE][MAX_CHARS_PER_LINE];
} Page;

typedef struct {
    char title[50];
    char author[50];
    int num_pages;
    Page pages[MAX_PAGES_PER_BOOK];
} Ebook;

void open_book(Ebook *book) {
    char filename[100];
    printf("Enter the filename of the book: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open the file!\n");
        exit(1);
    }

    // read the metadata
    fscanf(fp, "%s %s %d", book->title, book->author, &book->num_pages);

    // read each page
    for (int i = 0; i < book->num_pages; i++) {
        Page page;
        page.page_number = i+1;

        // read each line in the page
        for (int j = 0; j < MAX_LINES_PER_PAGE; j++) {
            if (fgets(page.lines[j], MAX_CHARS_PER_LINE, fp) == NULL) {
                break;
            }
            // remove the newline character
            page.lines[j][strlen(page.lines[j]) - 1] = '\0';
        }
        book->pages[i] = page;
    }

    fclose(fp);
}

void display_page(Ebook book, int page_number) {
    if (page_number < 1 || page_number > book.num_pages) {
        printf("Invalid page number!\n");
        return;
    }
    printf("\n\n%s, by %s\n", book.title, book.author);
    printf("Page %d of %d\n\n", page_number, book.num_pages);
    Page page = book.pages[page_number-1];
    for (int i = 0; i < MAX_LINES_PER_PAGE; i++) {
        if (page.lines[i][0] == '\0') {
            break;
        }
        printf("%s\n", page.lines[i]);
    }
}

int main() {
    Ebook book;
    open_book(&book);
    int page_number;
    while (1) {
        printf("\nEnter the page number (1 - %d) or 0 to exit: ", book.num_pages);
        scanf("%d", &page_number);
        if (page_number == 0) {
            break;
        }
        display_page(book, page_number);
    }
    printf("\nExiting the Ebook reader. Thank you for reading!\n");
    return 0;
}
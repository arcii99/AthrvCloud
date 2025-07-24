//FormAI DATASET v1.0 Category: Ebook reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_PAGES 1000
#define PAGE_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int num_pages;
    char pages[MAX_PAGES][PAGE_LENGTH];
} Book;

void print_title_page(Book book) {
    printf("TITLE: %s\n\n", book.title);
    printf("NUM PAGES: %d\n\n", book.num_pages);
    printf("PAGE 1:\n\n");
    printf("%s\n\n", book.pages[0]);
}

void print_page(Book book, int page_num) {
    if (page_num > book.num_pages) {
        printf("PAGE NUMBER DOES NOT EXIST.\n\n");
    } else {
        printf("PAGE %d:\n\n", page_num);
        printf("%s\n\n", book.pages[page_num - 1]);
    }
}

int main() {
    Book book;
    strcpy(book.title, "Romeo and Juliet");
    book.num_pages = 5;
    strcpy(book.pages[0], "Two households, both alike in dignity,");
    strcpy(book.pages[1], "In fair Verona, where we lay our scene,");
    strcpy(book.pages[2], "From ancient grudge break to new mutiny,");
    strcpy(book.pages[3], "Where civil blood makes civil hands unclean.");
    strcpy(book.pages[4], "From forth the fatal loins of these two foes");
    print_title_page(book);
    print_page(book, 3);
    return 0;
}
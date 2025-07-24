//FormAI DATASET v1.0 Category: Ebook reader ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PAGES 1000
#define MAX_PAGE_SIZE 10000

typedef struct {
    char* content;
    int page_number;
} Page;

typedef struct {
    Page pages[MAX_PAGES];
    int num_pages;
    int current_page;
    char* filename;
} Ebook;

int open_ebook(Ebook *ebook, char* filename) {
    ebook->filename = filename;
    ebook->num_pages = 0;
    ebook->current_page = 0;
    char line[MAX_PAGE_SIZE];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }
    while (fgets(line, MAX_PAGE_SIZE, fp) != NULL) {
        Page page;
        page.content = strdup(line);
        page.page_number = ebook->num_pages + 1;
        ebook->pages[ebook->num_pages++] = page;
    }
    return 1;
}

int close_ebook(Ebook *ebook) {
    int i;
    for (i = 0; i < ebook->num_pages; i++) {
        free(ebook->pages[i].content);
    }
    ebook->num_pages = 0;
    ebook->current_page = 0;
    ebook->filename = NULL;
    return 1;
}

int display_page(Ebook *ebook) {
    if (ebook->current_page < 0 || ebook->current_page >= ebook->num_pages) {
        printf("Error: Invalid page number.\n");
        return 0;
    }
    Page page = ebook->pages[ebook->current_page];
    printf("Page %d:\n\n%s\n", page.page_number, page.content);
    return 1;
}

int next_page(Ebook *ebook) {
    ebook->current_page++;
    if (ebook->current_page == ebook->num_pages) {
        printf("Error: Reached end of book.\n");
        return 0;
    }
    return display_page(ebook);
}

int prev_page(Ebook *ebook) {
    ebook->current_page--;
    if (ebook->current_page < 0) {
        printf("Error: Already at first page.\n");
        return 0;
    }
    return display_page(ebook);
}

int main() {
    Ebook ebook;
    open_ebook(&ebook, "book.txt");
    display_page(&ebook);
    next_page(&ebook);
    prev_page(&ebook);
    close_ebook(&ebook);
    return 0;
}
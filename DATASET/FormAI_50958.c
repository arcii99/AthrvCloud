//FormAI DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
/* A Sherlock Holmes inspired Ebook reader program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 1000
#define PAGE_LENGTH 1000

struct Ebook {
    char title[100];
    char author[100];
    char pages[MAX_PAGES][PAGE_LENGTH];
    int current_page_number;
};

typedef struct Ebook Ebook;

void initialize_ebook(Ebook *ebook, char *title, char *author, char *filename) {
    strcpy(ebook->title, title);
    strcpy(ebook->author, author);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    char page[PAGE_LENGTH];
    int page_count = 0;
    while(fgets(page, PAGE_LENGTH, fp) != NULL) {
        strcpy(ebook->pages[page_count], page);
        page_count++;
    }
    fclose(fp);
    ebook->current_page_number = 0;
}

void display_ebook_page(Ebook *ebook) {
    printf("Title: %s, Author: %s\n", ebook->title, ebook->author);
    printf("%s", ebook->pages[ebook->current_page_number]);
}

void go_to_next_page(Ebook *ebook) {
    if (ebook->current_page_number >= MAX_PAGES - 1) {
        printf("Error: Reached end of ebook\n");
        exit(1);
    }
    ebook->current_page_number++;
}

void go_to_previous_page(Ebook *ebook) {
    if (ebook->current_page_number <= 0) {
        printf("Error: At beginning of ebook\n");
        exit(1);
    }
    ebook->current_page_number--;
}

int main() {
    Ebook my_ebook;
    initialize_ebook(&my_ebook, "The Hound of the Baskervilles", "Sir Arthur Conan Doyle", "hound_of_the_baskervilles.txt");
    display_ebook_page(&my_ebook);
    go_to_next_page(&my_ebook);
    display_ebook_page(&my_ebook);
    go_to_next_page(&my_ebook);
    display_ebook_page(&my_ebook);
    go_to_previous_page(&my_ebook);
    display_ebook_page(&my_ebook);
    return 0;
}
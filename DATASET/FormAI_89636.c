//FormAI DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 50
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char* content;
} Ebook;

int num_ebooks = 0;
Ebook ebooks[MAX_EBOOKS];

void add_ebook(char title[], char author[], int pages, char content[]) {
    if (num_ebooks >= MAX_EBOOKS) {
        printf("Maximum number of ebooks reached!\n");
        return;
    }
    Ebook new_ebook;
    strcpy(new_ebook.title, title);
    strcpy(new_ebook.author, author);
    new_ebook.pages = pages;
    new_ebook.content = (char*) malloc(strlen(content) + 1);
    strcpy(new_ebook.content, content);
    ebooks[num_ebooks++] = new_ebook;
}

void print_ebook(Ebook ebook) {
    printf("\nTitle: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Pages: %d\n", ebook.pages);
    printf("---------\n");
    printf("%s", ebook.content);
    printf("---------\n");
}

void read_ebook(char title[]) {
    int found = 0;
    for (int i = 0; i < num_ebooks; i++) {
        if (strcmp(ebooks[i].title, title) == 0) {
            print_ebook(ebooks[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Ebook not found!\n");
    }
}

int main() {
    add_ebook("The C Programming Language", "Brian W. Kernighan", 274,
        "This book is a tutorial for the computer programming language C.");
    add_ebook("Head First Design Patterns", "Eric Freeman", 694,
        "They re designed to help you learn, remember, and recall.");
    add_ebook("Clean Code", "Robert C. Martin", 464,
        "This book is about the craft of software development.");
    read_ebook("The C Programming Language");
    read_ebook("Clean Code");
    read_ebook("The Catcher in the Rye");
    return 0;
}
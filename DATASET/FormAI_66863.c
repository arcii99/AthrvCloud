//FormAI DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_FILE_NAME_LENGTH 100
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    int num_pages;
    char page_content[MAX_PAGES][1000];
} book;

book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }

    book new_book;
    printf("Enter book title: ");
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);
    size_t len = strlen(new_book.title);
    if (len > 0 && new_book.title[len-1] == '\n') {
        new_book.title[--len] = '\0';
    }
    printf("Enter author name: ");
    fgets(new_book.author, MAX_AUTHOR_LENGTH, stdin);
    len = strlen(new_book.author);
    if (len > 0 && new_book.author[len-1] == '\n') {
        new_book.author[--len] = '\0';
    }
    printf("Enter file name: ");
    fgets(new_book.file_name, MAX_FILE_NAME_LENGTH, stdin);
    len = strlen(new_book.file_name);
    if (len > 0 && new_book.file_name[len-1] == '\n') {
        new_book.file_name[--len] = '\0';
    }
    printf("Enter number of pages: ");
    scanf("%d", &new_book.num_pages);
    getchar();

    for (int i = 0; i < new_book.num_pages; i++) {
        printf("Enter contents of page %d: ", i+1);
        fgets(new_book.page_content[i], 1000, stdin);
        len = strlen(new_book.page_content[i]);
        if (len > 0 && new_book.page_content[i][len-1] == '\n') {
            new_book.page_content[i][--len] = '\0';
        }
    }

    library[num_books++] = new_book;
    printf("Book added successfully.\n");
}

void read_book() {
    if (num_books == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Enter book title: ");
    char search_title[MAX_TITLE_LENGTH];
    fgets(search_title, MAX_TITLE_LENGTH, stdin);
    size_t len = strlen(search_title);
    if (len > 0 && search_title[len-1] == '\n') {
        search_title[--len] = '\0';
    }

    for (int i = 0; i < num_books; i++) {
        if (strcmp(search_title, library[i].title) == 0) {
            printf("Book: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Contents:\n");
            for (int j = 0; j < library[i].num_pages; j++) {
                printf("Page %d: %s\n", j+1, library[i].page_content[j]);
            }
            return;
        }
    }

    printf("Book not found.\n");
}

void list_books() {
    if (num_books == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("List of books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s - %s\n", i+1, library[i].title, library[i].author);
    }
}

int main() {
    printf("Welcome to Ebook Reader!\n");

    while (1) {
        printf("Menu:\n");
        printf("1. Add a book\n");
        printf("2. Read a book\n");
        printf("3. List all books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                read_book();
                break;
            case 3:
                list_books();
                break;
            case 4:
                printf("Thank you for using Ebook Reader!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
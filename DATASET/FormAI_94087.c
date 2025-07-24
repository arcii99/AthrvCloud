//FormAI DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_NAME_LENGTH 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_NAME_LENGTH];
    int year;
    char filepath[100];
} Book;

int numBooks = 0;
Book library[MAX_BOOKS];

void addBook(char title[MAX_TITLE_LENGTH], char author[MAX_AUTHOR_NAME_LENGTH], int year, char filepath[]) {
    if (numBooks < MAX_BOOKS) {
        strcpy(library[numBooks].title, title);
        strcpy(library[numBooks].author, author);
        library[numBooks].year = year;
        strcpy(library[numBooks].filepath, filepath);
        numBooks++;
        printf("%s by %s added to library.\n", title, author);
    } else {
        printf("Library is full.\n");
    }
}

void viewLibrary() {
    if (numBooks == 0) {
        printf("Library is empty.\n");
    } else {
        printf("Library:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("%d. %s by %s (%d)\n", i+1, library[i].title, library[i].author, library[i].year);
        }
    }
}

void readBook(int bookIndex) {
    if (bookIndex < 1 || bookIndex > numBooks) {
        printf("Invalid book index.\n");
        return;
    }
    printf("Opening %s...\n", library[bookIndex-1].title);
    printf("Reading %s by %s...\n", library[bookIndex-1].title, library[bookIndex-1].author);
    printf("%s\n", library[bookIndex-1].filepath);
}

int getMenuChoice() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Add book\n");
    printf("2. View library\n");
    printf("3. Read book\n");
    printf("4. Quit\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_NAME_LENGTH];
    int year;
    char filepath[100];
    while (1) {
        choice = getMenuChoice();
        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf("%s", title);
                printf("Enter book author: ");
                scanf("%s", author);
                printf("Enter year published: ");
                scanf("%d", &year);
                printf("Enter file path: ");
                scanf("%s", filepath);
                addBook(title, author, year, filepath);
                break;
            case 2:
                viewLibrary();
                break;
            case 3:
                int bookIndex;
                viewLibrary();
                printf("Enter book number to read: ");
                scanf("%d", &bookIndex);
                readBook(bookIndex);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_FILE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char file_path[MAX_FILE_LENGTH];
} Ebook;

void displayMenu();
void displayEbooks(Ebook ebooks[], int num_books);
void addEbook(Ebook ebooks[], int *num_books);
void removeEbook(Ebook ebooks[], int *num_books);
void readEbook(Ebook ebooks[], int num_books);

int main() {
    Ebook ebooks[MAX_EBOOKS];
    int num_books = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEbook(ebooks, &num_books);
                break;
            case 2:
                removeEbook(ebooks, &num_books);
                break;
            case 3:
                readEbook(ebooks, num_books);
                break;
            case 4:
                displayEbooks(ebooks, num_books);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n===== Ebook Reader =====\n");
    printf("1. Add Ebook\n");
    printf("2. Remove Ebook\n");
    printf("3. Read Ebook\n");
    printf("4. Display All Ebooks\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

void displayEbooks(Ebook ebooks[], int num_books) {
    if (num_books == 0) {
        printf("No ebooks found!\n");
        return;
    }

    printf("\n===== Ebooks (%d) =====\n", num_books);
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i + 1, ebooks[i].title, ebooks[i].author);
    }
}

void addEbook(Ebook ebooks[], int *num_books) {
    Ebook new_book;

    printf("\n===== Add Ebook =====\n");
    printf("Enter title: ");
    scanf(" %[^\n]s", new_book.title);
    printf("Enter author: ");
    scanf(" %[^\n]s", new_book.author);
    printf("Enter file path: ");
    scanf(" %[^\n]s", new_book.file_path);

    if (*num_books == MAX_EBOOKS) {
        printf("Maximum ebooks reached!\n");
        return;
    }

    ebooks[*num_books] = new_book;
    (*num_books)++;

    printf("Ebook added successfully!\n");
}

void removeEbook(Ebook ebooks[], int *num_books) {
    if (*num_books == 0) {
        printf("No ebooks found!\n");
        return;
    }

    int choice;
    displayEbooks(ebooks, *num_books);

    printf("\nEnter ebook number to remove: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > *num_books) {
        printf("Invalid ebook number!\n");
        return;
    }

    for (int i = choice - 1; i < *num_books - 1; i++) {
        ebooks[i] = ebooks[i + 1];
    }

    (*num_books)--;

    printf("Ebook removed successfully!\n");
}

void readEbook(Ebook ebooks[], int num_books) {
    if (num_books == 0) {
        printf("No ebooks found!\n");
        return;
    }

    int choice;
    displayEbooks(ebooks, num_books);

    printf("\nEnter ebook number to read: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_books) {
        printf("Invalid ebook number!\n");
        return;
    }

    printf("\nReading %s by %s...\n", ebooks[choice - 1].title, ebooks[choice - 1].author);
    printf("Opening file %s...\n", ebooks[choice - 1].file_path);
    // code to read ebook file goes here
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_FILENAME_LEN 50
#define MAX_BOOKS 10
#define MAX_PAGES 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char filename[MAX_FILENAME_LEN];
    int num_pages;
    char pages[MAX_PAGES][100];
} Book;

Book books[MAX_BOOKS];
int num_books = 0;

int show_menu() {
    int choice;
    printf("1. Add new book\n");
    printf("2. View book\n");
    printf("3. Quit\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_new_book() {
    if(num_books == MAX_BOOKS) {
        printf("Maximum number of books reached.\n");
        return;
    }

    Book new_book;
    printf("Enter book title: ");
    scanf("%s", new_book.title);
    printf("Enter filename (including .txt): ");
    scanf("%s", new_book.filename);

    FILE *file = fopen(new_book.filename, "r");
    if(file == NULL) {
        printf("Could not open file\n");
        return;
    }

    int page_count = 0;
    while(fgets(new_book.pages[page_count], 100, file) != NULL) {
        page_count++;
    }
    new_book.num_pages = page_count;
    strcpy(books[num_books].title, new_book.title);
    strcpy(books[num_books].filename, new_book.filename);
    books[num_books].num_pages = new_book.num_pages;
    for(int i = 0; i < new_book.num_pages; i++) {
        strcpy(books[num_books].pages[i], new_book.pages[i]);
    }

    fclose(file);
    num_books++;
    printf("Book added successfully.\n");
}

void view_book() {
    if(num_books == 0) {
        printf("There are no books to view.\n");
        return;
    }

    int book_choice;
    printf("Select a book to view:\n");
    for(int i = 0; i < num_books; i++) {
        printf("%d. %s\n", i + 1, books[i].title);
    }
    printf("\nEnter choice: ");
    scanf("%d", &book_choice);

    if(book_choice < 1 || book_choice > num_books) {
        printf("Invalid choice.\n");
        return;
    }

    printf("%s\n", books[book_choice - 1].title);
    for(int i = 0; i < books[book_choice - 1].num_pages; i++) {
        printf("%s", books[book_choice - 1].pages[i]);
    }
}

int main() {
    int choice = show_menu();
    while(choice != 3) {
        switch(choice) {
            case 1: add_new_book();
                    break;
            case 2: view_book();
                    break;
            default: printf("Invalid choice.\n");
                     break;
        }
        choice = show_menu();
    }
    printf("Goodbye!\n");
    return 0;
}
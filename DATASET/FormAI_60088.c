//FormAI DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_PAGES 5000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

int main() {
    
    Book library[MAX_BOOKS];
    int num_books = 0;
    
    // Add a book to the library
    void add_book() {
        if (num_books == MAX_BOOKS) {
            printf("The library is full.\n");
            return;
        }
        Book new_book;
        printf("Enter the book's title:\n");
        scanf("%s", new_book.title);
        printf("Enter the book's author:\n");
        scanf("%s", new_book.author);
        printf("Enter the number of pages:\n");
        scanf("%d", &new_book.pages);
        library[num_books] = new_book;
        num_books++;
        printf("Book added to the library!\n");
    }
    
    // Remove a book from the library
    void remove_book() {
        if (num_books == 0) {
            printf("The library is empty.\n");
            return;
        }
        printf("Enter the title of the book you want to remove:\n");
        char title[MAX_TITLE_LENGTH];
        scanf("%s", title);
        for (int i = 0; i < num_books; i++) {
            if (strcmp(library[i].title, title) == 0) {
                for (int j = i; j < num_books - 1; j++) {
                    library[j] = library[j+1];
                }
                num_books--;
                printf("Book removed from the library.\n");
                return;
            }
        }
        printf("The book was not found in the library.\n");
    }
    
    // Print the list of books in the library
    void print_books() {
        if (num_books == 0) {
            printf("The library is empty.\n");
            return;
        }
        printf("Library Contents:\n");
        for (int i = 0; i < num_books; i++) {
            printf("%s by %s - %d pages\n", library[i].title, library[i].author, library[i].pages);
        }
    }
    
    // Main menu loop
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a book to the library\n");
        printf("2. Remove a book from the library\n");
        printf("3. Print the list of books in the library\n");
        printf("4. Quit the program\n");
        printf("Enter your choice (1-4):\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_book();
                break;
            case 2:
                remove_book();
                break;
            case 3:
                print_books();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 128 // Maximum length of eBook title
#define MAX_AUTHOR_LENGTH 64 // Maximum length of an author's name
#define MAX_BOOKS 100 // Maximum number of books that can be stored in the program
#define MAX_PAGES 5000 // Maximum number of pages in an eBook
#define PASSWORD "mySecurePassword123" // Password for accessing the program

typedef struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int num_pages;
    char *content;
} Book;

Book* books[MAX_BOOKS]; // Array of pointers to Book structures
int num_books = 0; // Number of books currently stored in the program

void add_book() {
    if(num_books >= MAX_BOOKS) {
        printf("Error: Maximum number of books reached.\n");
        return;
    }
    Book* new_book = (Book*) malloc(sizeof(Book)); // Allocate memory for new book
    printf("Enter book title: ");
    fgets(new_book->title, MAX_TITLE_LENGTH, stdin);
    printf("Enter author name: ");
    fgets(new_book->author, MAX_AUTHOR_LENGTH, stdin);
    printf("Enter number of pages: ");
    scanf("%d", &(new_book->num_pages));
    getchar(); // Clear the stdin buffer
    new_book->content = (char*) malloc(new_book->num_pages * sizeof(char)); // Allocate memory for book content
    printf("Enter book contents (press Enter after each page):\n");
    for(int i = 0; i < new_book->num_pages; ++i) {
        fgets((new_book->content) + i, MAX_PAGES, stdin);
    }
    new_book->id = num_books; // Assign unique ID to the book
    books[num_books++] = new_book; // Add book to the library
    printf("Book added successfully!\n");
}

void remove_book() {
    int id;
    printf("Enter book ID to remove: ");
    scanf("%d", &id);
    getchar(); // Clear the stdin buffer
    if(id >= num_books || id < 0 || books[id] == NULL) {
        printf("Error: Invalid book ID.\n");
        return;
    }
    free(books[id]->content); // Free memory allocated to book content
    free(books[id]); // Free memory allocated to book structure
    books[id] = NULL; // Set pointer to NULL
    printf("Book removed successfully!\n");
}

void view_book() {
    int id;
    printf("Enter book ID to view: ");
    scanf("%d", &id);
    getchar(); // Clear the stdin buffer
    if(id >= num_books || id < 0 || books[id] == NULL) {
        printf("Error: Invalid book ID.\n");
        return;
    }
    printf("Book #%d - %s by %s (%d pages):\n\n", id, books[id]->title, books[id]->author, books[id]->num_pages);
    for(int i = 0; i < books[id]->num_pages; ++i) {
        printf("%s", (books[id]->content) + i);
    }
}

void list_books() {
    printf("Listing all books (ID - Title by Author):\n");
    for(int i = 0; i < num_books; ++i) {
        if(books[i] != NULL) {
            printf("%d - %s by %s\n", books[i]->id, books[i]->title, books[i]->author);
        }
    }
}

int main() {
    printf("Welcome to my Ebook Reader!\n");
    char password[MAX_TITLE_LENGTH];
    printf("Please enter the password: ");
    fgets(password, MAX_TITLE_LENGTH, stdin);
    if(strcmp(password, PASSWORD) != 0) { // Check if password is correct
        printf("Error: Incorrect password.\n");
        return 0;
    }
    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a book\n");
        printf("2. Remove a book\n");
        printf("3. View a book\n");
        printf("4. List all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the stdin buffer
        switch(choice) {
            case 1:
                add_book();
                break;
            case 2:
                remove_book();
                break;
            case 3:
                view_book();
                break;
            case 4:
                list_books();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
    } while(choice != 5);
    return 0;
}
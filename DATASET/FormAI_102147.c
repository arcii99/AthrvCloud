//FormAI DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the menu
void displayMenu() {
    printf("Welcome to the C EBook reader!\n");
    printf("1. View Book\n");
    printf("2. Search Book\n");
    printf("3. Add Bookmark\n");
    printf("4. Exit\n");
}

// Function to view a book
void viewBook(char* book_name) {
    // Open the file
    FILE* fp = fopen(book_name, "r");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Read the contents of the file and print them on console
    char contents[1000];
    while (fgets(contents, sizeof(contents), fp) != NULL) {
        printf("%s", contents);
    }

    // Close the file
    fclose(fp);
}

// Function to search for a book and return its path
char* searchBook(char* book_name) {
    char* path = malloc(sizeof(char) * 100);

    // Set the path of the book file
    strcpy(path, "c:/library/books/");
    strcat(path, book_name);
    strcat(path, ".txt");

    // Check if the file exists
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        printf("The requested book is not available.\n");
        return NULL;
    }

    // Close the file and return the path
    fclose(fp);
    return path;
}

// Structure for the bookmark
struct Bookmark {
    char* book_name;
    int page_number;
};

int main() {
    // Display the menu
    displayMenu();

    // Create an empty bookmark
    struct Bookmark bookmark;
    bookmark.book_name = "";
    bookmark.page_number = 0;

    // Loop until the user exits
    while (1) {
        // Get the user's choice
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Execute the appropriate functionality based on the user's choice
        switch (choice) {
            case 1:
                if (strcmp(bookmark.book_name, "") != 0) {
                    // If the user has set a bookmark, ask if they would like to resume from that page
                    char resume_from_bookmark;
                    printf("Would you like to resume from your bookmark? (Y/N): ");
                    scanf(" %c", &resume_from_bookmark);
                    if (resume_from_bookmark == 'Y' || resume_from_bookmark == 'y') {
                        viewBook(bookmark.book_name);
                        printf("Resuming from page %d...\n", bookmark.page_number);
                    } else {
                        // If not, ask the user to enter the desired page number
                        printf("Enter the page number you would like to read from: ");
                        int page_number;
                        scanf("%d", &page_number);
                        viewBook(bookmark.book_name);
                        printf("Starting from page %d...\n", page_number);
                    }
                } else {
                    // If there is no bookmark set, ask the user to enter the desired page number
                    printf("Enter the page number you would like to read from: ");
                    int page_number;
                    scanf("%d", &page_number);
                    char book_name[50];
                    printf("Enter the name of the book you would like to read: ");
                    scanf("%s", book_name);

                    // Search for the book
                    char* path = searchBook(book_name);
                    if (path == NULL) {
                        break;
                    }

                    // Set the bookmark struct values
                    bookmark.book_name = book_name;
                    bookmark.page_number = page_number;

                    // Display the book
                    viewBook(book_name);
                    printf("Starting from page %d...\n", page_number);
                }
                break;

            case 2:
                // Ask the user to enter the name of the book to search for
                char book_name[50];
                printf("Enter the name of the book you would like to search for: ");
                scanf("%s", book_name);

                // Search for the book
                char* path = searchBook(book_name);
                if (path == NULL) {
                    break;
                }

                // Display the path of the book
                printf("The book is available at: %s\n", path);
                break;

            case 3:
                if (strcmp(bookmark.book_name, "") != 0) {
                    // If there is a bookmark set, display its current values
                    printf("Current bookmark:\n");
                    printf("Book name: %s\n", bookmark.book_name);
                    printf("Page number: %d\n", bookmark.page_number);
                } else {
                    printf("There is no bookmark set!\n");
                }
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
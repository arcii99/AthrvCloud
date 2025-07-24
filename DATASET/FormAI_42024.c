//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of books
#define MAX_BOOKS 100

// Define the book structure
typedef struct {
    char title[50];
    char author[30];
    int pages;
    int year;
    int ISBN;
    char format[10];
    float price;
} book;

int main() {

    // Declare variables
    book books[MAX_BOOKS];
    int num_books = 0;
    int choice, i;
    FILE *file;

    // Initialize the book array with empty books
    for (i = 0; i < MAX_BOOKS; i++) {
        books[i].title[0] = '\0';
    }

    // Prompt the user to choose an option
    printf("*** Welcome to the C Ebook Reader Example Program ***\n");
    printf("1. Add a book\n");
    printf("2. List all books\n");
    printf("3. Search for a book\n");
    printf("4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Execute the user's choice
        switch (choice) {
            case 1:
                // Add a new book
                if (num_books < MAX_BOOKS) {
                    printf("Enter the book's title: ");
                    scanf("%s", books[num_books].title);
                    printf("Enter the book's author: ");
                    scanf("%s", books[num_books].author);
                    printf("Enter the book's number of pages: ");
                    scanf("%d", &books[num_books].pages);
                    printf("Enter the book's year of publication: ");
                    scanf("%d", &books[num_books].year);
                    printf("Enter the book's ISBN: ");
                    scanf("%d", &books[num_books].ISBN);
                    printf("Enter the book's format: ");
                    scanf("%s", books[num_books].format);
                    printf("Enter the book's price: ");
                    scanf("%f", &books[num_books].price);
                    num_books++;
                } else {
                    printf("Error: Maximum number of books exceeded.\n");
                }
                break;
            case 2:
                // List all books
                printf("Listing all books:\n");
                for (i = 0; i < num_books; i++) {
                    printf("%s by %s\n", books[i].title, books[i].author);
                }
                break;
            case 3:
                // Search for a book
                char title_search[50];
                int found = 0;
                printf("Enter the title of the book to search for: ");
                scanf("%s", title_search);
                for (i = 0; i < num_books; i++) {
                    if (strcmp(title_search, books[i].title) == 0) {
                        printf("Book found:\n");
                        printf("%s by %s\n", books[i].title, books[i].author);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Book not found.\n");
                }
                break;
            case 4:
                // Exit the program
                printf("Exiting the program.\n");
                break;
            default:
                // Invalid choice
                printf("Error: Invalid choice.\n");
                break;
        }

    } while (choice != 4);

    // Write the book data to a file
    file = fopen("books.txt", "w");
    for (i = 0; i < num_books; i++) {
        fprintf(file, "%s,%s,%d,%d,%d,%s,%.2f\n", books[i].title, books[i].author,
          books[i].pages, books[i].year, books[i].ISBN, books[i].format, books[i].price);
    }
    fclose(file);

    // Read the book data from the file
    file = fopen("books.txt", "r");
    while (fscanf(file, "%[^,],%[^,],%d,%d,%d,%[^,],%f\n", books[num_books].title,
      books[num_books].author, &books[num_books].pages, &books[num_books].year,
      &books[num_books].ISBN, books[num_books].format, &books[num_books].price) == 7) {
        num_books++;
    }
    fclose(file);

    // Print the book data from the file
    printf("Printing book data from file:\n");
    for (i = 0; i < num_books; i++) {
        printf("%s by %s\n", books[i].title, books[i].author);
    }

    return 0;
}
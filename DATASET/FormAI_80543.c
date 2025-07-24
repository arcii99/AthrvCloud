//FormAI DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_PAGES 1000
#define MAX_CHARACTERS 100

struct Book {
    char title[MAX_CHARACTERS];
    char author[MAX_CHARACTERS];
    char publisher[MAX_CHARACTERS];
    int num_pages;
    char pages[MAX_PAGES][MAX_CHARACTERS];
};

struct Book books[MAX_BOOKS];

int main() {
    int num_books = 0;
    char input[MAX_CHARACTERS];
    int option = 0;
    int book_index = 0;
    int page_num = 0;
    
    // Loop until the user decides to exit
    while (option != 4) {
        printf("Select an option:\n");
        printf("1. Add a book\n");
        printf("2. View a book\n");
        printf("3. Read a book\n");
        printf("4. Exit\n");
        fgets(input, MAX_CHARACTERS, stdin);
        option = atoi(input);
        
        switch(option) {
            // Add a book
            case 1:
                if (num_books < MAX_BOOKS) {
                    struct Book book;
                    printf("Enter the title: ");
                    fgets(book.title, MAX_CHARACTERS, stdin);
                    printf("Enter the author: ");
                    fgets(book.author, MAX_CHARACTERS, stdin);
                    printf("Enter the publisher: ");
                    fgets(book.publisher, MAX_CHARACTERS, stdin);
                    printf("Enter the number of pages: ");
                    fgets(input, MAX_CHARACTERS, stdin);
                    book.num_pages = atoi(input);
                    for (int i = 0; i < book.num_pages; i++) {
                        printf("Enter the text for page %d: ", i+1);
                        fgets(book.pages[i], MAX_CHARACTERS, stdin);
                    }
                    books[num_books++] = book;
                    printf("Book added!\n");
                }
                else {
                    printf("Maximum number of books reached.\n");
                }
                break;
            // View a book
            case 2:
                if (num_books > 0) {
                    printf("Enter the index of the book to view: ");
                    fgets(input, MAX_CHARACTERS, stdin);
                    book_index = atoi(input);
                    if (book_index >= 0 && book_index < num_books) {
                        struct Book book = books[book_index];
                        printf("Title: %s", book.title);
                        printf("Author: %s", book.author);
                        printf("Publisher: %s", book.publisher);
                        printf("Number of pages: %d\n", book.num_pages);
                        for (int i = 0; i < book.num_pages; i++) {
                            printf("Page %d:\n%s", i+1, book.pages[i]);
                        }
                    }
                    else {
                        printf("Invalid index.\n");
                    }
                }
                else {
                    printf("No books to view.\n");
                }
                break;
            // Read a book
            case 3:
                if (num_books > 0) {
                    printf("Enter the index of the book to read: ");
                    fgets(input, MAX_CHARACTERS, stdin);
                    book_index = atoi(input);
                    if (book_index >= 0 && book_index < num_books) {
                        struct Book book = books[book_index];
                        printf("Enter the page number to start reading from: ");
                        fgets(input, MAX_CHARACTERS, stdin);
                        page_num = atoi(input);
                        if (page_num >= 1 && page_num <= book.num_pages) {
                            printf("Reading book %d, starting from page %d:\n", book_index+1, page_num);
                            for (int i = page_num-1; i < book.num_pages; i++) {
                                printf("Page %d:\n%s", i+1, book.pages[i]);
                                printf("\nPress Enter to continue reading or 'q' to stop: ");
                                fgets(input, MAX_CHARACTERS, stdin);
                                if (input[0] == 'q') {
                                    printf("Stopping reading.\n");
                                    break;
                                }
                            }
                        }
                        else {
                            printf("Invalid page number.\n");
                        }
                    }
                    else {
                        printf("Invalid index.\n");
                    }
                }
                else {
                    printf("No books to read.\n");
                }
                break;
            // Exit
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    
    return 0;
}
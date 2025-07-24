//FormAI DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum number of books
#define MAX_BOOKS 3

// Define the maximum name length for a book
#define MAX_NAME_LEN 50

// Define the maximum number of pages for a book
#define MAX_PAGES 500

// Define the book structure
struct Book {
    char name[MAX_NAME_LEN];
    int pages;
    char* content;
};

// Define the EbookReader structure
struct EbookReader {
    struct Book books[MAX_BOOKS];
    int current_book_index;
};

// Function to initialize the EbookReader
void init_ebook_reader(struct EbookReader* reader) {
    // Set the current book index to -1
    reader->current_book_index = -1;
    // Set the book names and number of pages
    strcpy(reader->books[0].name, "The Alchemist");
    reader->books[0].pages = 172;
    strcpy(reader->books[1].name, "The God of Small Things");
    reader->books[1].pages = 355;
    strcpy(reader->books[2].name, "The Catcher in the Rye");
    reader->books[2].pages = 277;
    // Allocate memory for content of each book
    reader->books[0].content = (char*)malloc(reader->books[0].pages * sizeof(char));
    reader->books[1].content = (char*)malloc(reader->books[1].pages * sizeof(char));
    reader->books[2].content = (char*)malloc(reader->books[2].pages * sizeof(char));
    // Add some random text to each book
    strcpy(reader->books[0].content, "Paulo Coelho's masterpiece tells the mystical story of Santiago, an Andalusian shepherd boy who yearns to travel in search of a worldly treasure as extravagant as any ever found.");
    strcpy(reader->books[1].content, "Arundhati Roy’s novel is a modern classic that has been read and loved worldwide. It is one of the most famous Indian novels in English. ");
    strcpy(reader->books[2].content, "The famous tale by J.D. Salinger of teenage angst and rebellion was first published in 1951 and remains a true classic today. ");
}

// Function to display the EbookReader menu
void display_menu() {
    printf("Welcome to EbookReader!\n");
    printf("Please choose an option:\n");
    printf("1. View available books\n");
    printf("2. Select a book\n");
    printf("3. Read current book\n");
    printf("4. Exit EbookReader\n");
}

// Function to display the available books
void display_books(struct EbookReader* reader) {
    printf("The available books are:\n");
    for (int i=0; i<MAX_BOOKS; i++) {
        printf("%d. %s (%d pages)\n", i+1, reader->books[i].name, reader->books[i].pages);
    }
}

// Function to select a book
void select_book(struct EbookReader* reader, int book_index) {
    // Set the current book index
    reader->current_book_index = book_index;
    printf("%s has been selected.\n", reader->books[book_index].name);
}

// Function to read the current book
void read_book(struct EbookReader* reader) {
    if (reader->current_book_index == -1) {
        printf("No book is currently selected.\n");
        return;
    }
    printf("The content of the book is:\n");
    printf("%s\n", reader->books[reader->current_book_index].content);
}

int main() {
    struct EbookReader reader;
    init_ebook_reader(&reader);
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_books(&reader);
                break;
            case 2:
                printf("Enter the index of the book you wish to select (1-%d):\n", MAX_BOOKS);
                int book_index;
                scanf("%d", &book_index);
                if (book_index < 1 || book_index > MAX_BOOKS) {
                    printf("Invalid book index.\n");
                } else {
                    select_book(&reader, book_index-1);
                }
                break;
            case 3:
                read_book(&reader);
                break;
            case 4:
                // Quit EbookReader
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    } while(choice != 4);
    // Free memory for book content
    free(reader.books[0].content);
    free(reader.books[1].content);
    free(reader.books[2].content);
    return 0;
}
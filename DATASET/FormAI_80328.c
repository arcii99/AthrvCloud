//FormAI DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters allowed in the book name.
#define MAX_BOOK_NAME_LENGTH 100

// Define the maximum number of pages in the book.
#define MAX_PAGES 500

// Define the maximum number of bookmarks allowed per book.
#define MAX_BOOKMARKS 10

// Define a structure to store information about each bookmark.
struct Bookmark {
    int page;
    char name[MAX_BOOK_NAME_LENGTH];
};

// Define a structure to store information about the book.
struct Book {
    char name[MAX_BOOK_NAME_LENGTH];
    int totalPages;
    int currentPage;
    struct Bookmark bookmarks[MAX_BOOKMARKS];
    int bookmarkCount;
};

// Function to add bookmark to the book.
void addBookmark(struct Book *book) {
    if (book->bookmarkCount >= MAX_BOOKMARKS) {
        printf("Maximum number of bookmarks reached for this book.\n");
        return;
    }

    struct Bookmark *bookmark = &book->bookmarks[book->bookmarkCount];

    printf("Enter bookmark name: ");
    scanf("%s", bookmark->name);

    printf("Enter bookmark page number: ");
    scanf("%d", &bookmark->page);

    book->bookmarkCount++;

    printf("Bookmark added successfully.\n");
}

// Function to remove bookmark from the book.
void removeBookmark(struct Book *book, int bookmarkIndex) {
    if (bookmarkIndex < 0 || bookmarkIndex >= book->bookmarkCount) {
        printf("Invalid bookmark index.\n");
        return;
    }

    memmove(&book->bookmarks[bookmarkIndex], &book->bookmarks[bookmarkIndex + 1], sizeof(struct Bookmark) * (book->bookmarkCount - bookmarkIndex - 1));

    book->bookmarkCount--;

    printf("Bookmark removed successfully.\n");
}

// Function to display all bookmarks in the book.
void displayBookmarks(struct Book *book) {
    if (book->bookmarkCount == 0) {
        printf("No bookmarks found for this book.\n");
        return;
    }

    printf("Bookmarks for %s:\n", book->name);

    for (int i = 0; i < book->bookmarkCount; i++) {
        printf("%d: %s - Page %d\n", i + 1, book->bookmarks[i].name, book->bookmarks[i].page);
    }
}

// Function to display information about the book.
void displayBook(struct Book *book) {
    printf("Name: %s\n", book->name);
    printf("Total pages: %d\n", book->totalPages);
    printf("Current page: %d\n", book->currentPage);
}

int main() {
    struct Book book;
    book.bookmarkCount = 0;

    printf("Enter book name: ");
    fgets(book.name, MAX_BOOK_NAME_LENGTH, stdin);

    printf("Enter total pages in book: ");
    scanf("%d", &book.totalPages);

    printf("Enter current page number: ");
    scanf("%d", &book.currentPage);

    // Menu loop
    while (1) {
        printf("\n1. Add bookmark\n2. Remove bookmark\n3. Display bookmarks\n4. Display book info\n5. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBookmark(&book);
                break;
            case 2:
                int bookmarkIndex;
                printf("Enter bookmark index to delete: ");
                scanf("%d", &bookmarkIndex);
                removeBookmark(&book, bookmarkIndex - 1);
                break;
            case 3:
                displayBookmarks(&book);
                break;
            case 4:
                displayBook(&book);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Book struct
typedef struct Book {
    char* title;
    char* author;
    int page_count;
} Book;

// Ebook struct that contains book data and current page
typedef struct Ebook {
    Book book;
    int current_page;
} Ebook;

// Function to display book information
void display_book_info(Ebook ebook) {
    printf("Title: %s\n", ebook.book.title);
    printf("Author: %s\n", ebook.book.author);
    printf("Page count: %d\n", ebook.book.page_count);
    printf("Current page: %d\n\n", ebook.current_page);
}

// Function to update current page
void update_current_page(Ebook* ebook, int new_page) {
    // Ensure the new page is within the book limits
    if (new_page < 1 || new_page > ebook->book.page_count) {
        printf("Invalid page number\n\n");
    }
    else {
        ebook->current_page = new_page;
        printf("Current page updated to %d\n\n", ebook->current_page);
    }
}

int main() {
    // Create Ebook object with book data and default current page of 1
    Ebook ebook = { {"The Great Gatsby", "F. Scott Fitzgerald", 180}, 1 };
    
    // Display book information
    display_book_info(ebook);
    
    // Update current page to 50
    update_current_page(&ebook, 50);
    
    // Display book information again to verify current page update
    display_book_info(ebook);
    
    // Update current page to invalid value
    update_current_page(&ebook, 200);
    
    // Display book information again to show current page did not update
    display_book_info(ebook);
    
    return 0;
}
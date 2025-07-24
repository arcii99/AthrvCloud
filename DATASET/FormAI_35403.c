//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_PAGES 100

char* scan_input();
void read_ebook(char *book_title);
void display_page(char *page_content);
bool is_page_safe(char *page_content);

int main() {

    char *selected_book;

    // Load available books
    char *available_books[MAX_BOOKS];
    available_books[0] = "Cryptography for Dummies";
    available_books[1] = "Top Secret Government Documents";
    available_books[2] = "The Paranoid's Guide to Surviving the Apocalypse";

    // Display available books
    printf("Available books:\n");
    for(int i=0; i<3; i++) {
        printf("%d. %s\n", i+1, available_books[i]);
    }

    // User selects book
    printf("\nPlease select a book: ");
    selected_book = scan_input();

    // User reads ebook
    read_ebook(selected_book);
    
    return 0;
}

char* scan_input() {

    char *input = (char*)malloc(MAX_PAGES*sizeof(char));
    scanf("%[^\n]%*c", input);
    return input;

}

void read_ebook(char *book_title) {

    char *book_pages[MAX_PAGES];
    book_pages[0] = "The government is always watching us.";
    book_pages[1] = "The encryption methods used by the NSA are vulnerable.";
    book_pages[2] = "The zombie virus may have already been released.";

    printf("\n%s\n\n", book_title);

    for(int i=0; i<3; i++) {
        if(is_page_safe(book_pages[i])) {
            display_page(book_pages[i]);
        } else {
            printf("This page may not be safe to display.\n");
        }
    }

}

void display_page(char *page_content) {

    printf("%s\n", page_content);

}

bool is_page_safe(char *page_content) {

    // "Paranoid checksum" to validate page content
    int page_checksum = 0;
    for(int i=0; i<strlen(page_content); i++) {
        page_checksum += (int)page_content[i];
    }

    // Random decision based on paranoid criteria
    int safe_probability = rand() % 10;
    if(safe_probability < 3 && page_checksum % 2 == 0) {
        return false;
    } else {
        return true;
    }

}
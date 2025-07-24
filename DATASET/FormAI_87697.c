//FormAI DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    char author[50];
    int pages;
    int current_page;
    char text[10000];
};

typedef struct book Book;

void print_book(Book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
    printf("Current page: %d\n", b.current_page);
}

int main() {
    Book my_book;
    strcpy(my_book.title, "The Adventures of Sherlock Holmes");
    strcpy(my_book.author, "Arthur Conan Doyle");
    my_book.pages = 320;
    my_book.current_page = 10;
    // Read in the text of the book from a file and store it in my_book.text
    
    print_book(my_book);
    
    // Display the text of the book to the user
    for (int i = 0; i < my_book.pages; i++) {
        printf("%s", my_book.text + i*100);
        printf("\n\n");
        int page_choice = 0;
        scanf("%d", &page_choice);
        if (page_choice == 0) {
            break;
        }
        my_book.current_page = page_choice;
    }
    return 0;
}
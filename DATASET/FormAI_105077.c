//FormAI DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 50
#define MAX_PAGE_LENGTH 200

typedef struct {
    char title[50];
    char author[50];
} Book;

typedef struct {
    Book book;
    char pages[MAX_PAGE_LENGTH][MAX_PAGE_LENGTH];
    int current_page;
} Ebook;

int num_books = 0;
Book library[MAX_BOOKS];

void add_book(char *title, char *author) {
    if (num_books >= MAX_BOOKS) {
        printf("Sorry, the library is full.\n");
        return;
    }
    Book new_book;
    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    library[num_books] = new_book;
    num_books++;
    printf("The book \"%s\" by %s has been added to the library.\n", title, author);
}

void print_library() {
    printf("=== Library ===\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. \"%s\" by %s\n", i+1, library[i].title, library[i].author);
    }
}

void read_ebook(Book book) {
    Ebook ebook;
    ebook.book = book;
    ebook.current_page = 0;
    printf("=== %s ===\n", ebook.book.title);
    // read pages from file or database and store in ebook.pages
    for (int i = 0; i < MAX_PAGE_LENGTH; i++) {
        if (strlen(ebook.pages[i]) > 0) {
            printf("%s\n", ebook.pages[i]);
            ebook.current_page++;
        } else {
            break;
        }
    }
    printf("=== End of Book ===\n");
}

int main() {
    add_book("The Alchemist", "Paulo Coelho");
    add_book("To Kill a Mockingbird", "Harper Lee");
    add_book("1984", "George Orwell");
    print_library();
    int choice;
    printf("Enter the number of the book you want to read: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > num_books) {
        printf("Sorry, that is not a valid book choice.\n");
        return 0;
    }
    read_ebook(library[choice-1]);
    return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 50
#define MAX_PAGES 500

struct book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int page_count;
    char *pages[MAX_PAGES];
};

struct library {
    struct book books[MAX_BOOKS];
    int book_count;
};

struct book new_book(char title[], char author[], int page_count) {
    struct book b;
    strcpy(b.title, title);
    strcpy(b.author, author);
    b.page_count = page_count;
    for (int i = 0; i < page_count; i++) {
        char *page = (char*) malloc(100*sizeof(char));
        sprintf(page, "This is page number %d", i+1);
        b.pages[i] = page;
    }
    return b;
}

void read_book(struct book b) {
    printf("*** %s - %s ***\n\n", b.title, b.author);
    for (int i = 0; i < b.page_count; i++) {
        printf("%s\n", b.pages[i]);
    }
    printf("\n");
}

void add_book(struct library *lib, struct book b) {
    if (lib->book_count < MAX_BOOKS) {
        lib->books[lib->book_count] = b;
        lib->book_count++;
    } else {
        printf("Library is full!\n");
    }
}

int main() {
    struct library lib;
    lib.book_count = 0;

    struct book b1 = new_book("The Great Gatsby", "F. Scott Fitzgerald", 10);
    struct book b2 = new_book("To Kill a Mockingbird", "Harper Lee", 15);
    struct book b3 = new_book("1984", "George Orwell", 20);

    add_book(&lib, b1);
    add_book(&lib, b2);
    add_book(&lib, b3);

    for (int i = 0; i < lib.book_count; i++) {
        read_book(lib.books[i]);
    }

    return 0;
}
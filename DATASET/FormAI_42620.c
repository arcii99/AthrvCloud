//FormAI DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;

typedef struct {
    char name[100];
    Book books[10];
    int num_books;
} Library;

void add_book(Library *lib, char *title, char *author, int year) {
    Book new_book;
    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    new_book.year = year;
    lib->books[lib->num_books] = new_book;
    lib->num_books++;
}

void print_books(Library *lib) {
    printf("%s's Library:\n", lib->name);
    for (int i = 0; i < lib->num_books; i++) {
        printf("%s by %s (%d)\n", lib->books[i].title, lib->books[i].author, lib->books[i].year);
    }
}

int main() {
    Library romeo_library = {"Romeo", {}, 0};
    Library juliet_library = {"Juliet", {}, 0};
    add_book(&romeo_library, "Romeo and Juliet", "William Shakespeare", 1597);
    add_book(&juliet_library, "Romeo and Juliet", "William Shakespeare", 1597);
    printf("Romeo and Juliet met at the local library.\n");
    printf("Romeo saw that Juliet was reading the same book as him.\n");
    printf("Romeo: 'Excuse me, but that's my favorite book!'\n");
    printf("Juliet: 'Really? It's my favorite too!'\n");
    printf("Romeo: 'Would you like to borrow my copy?'\n");
    printf("Juliet: 'Oh, that's so sweet of you!'\n");
    printf("Romeo lends Juliet his copy of Romeo and Juliet.\n");
    add_book(&juliet_library, "Hamlet", "William Shakespeare", 1600);
    printf("Juliet: 'I have a book that you might enjoy too!'\n");
    printf("Juliet lends Romeo her copy of Hamlet.\n");
    printf("Romeo and Juliet continue to borrow books from each other and fall in love.\n");
    print_books(&romeo_library);
    print_books(&juliet_library);
    return 0;
}
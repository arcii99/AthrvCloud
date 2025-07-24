//FormAI DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    float price;
    int pages;
} Book;

typedef struct {
    Book library[MAX_BOOKS];
    int num_books;
} EbookReader;

void add_book(EbookReader *reader, Book new_book) {
    if (reader->num_books < MAX_BOOKS) {
        reader->library[reader->num_books] = new_book;
        reader->num_books++;
        printf("You've added '%s' by %s to your Ebook Reader!\n", new_book.title, new_book.author);
    } else {
        printf("Sorry, your Ebook Reader is full!\n");
    }
}

void print_books(EbookReader reader) {
    for (int i = 0; i < reader.num_books; i++) {
        printf("\nTitle: %s\nAuthor: %s\nPrice: %.2f\nPages: %d\n", reader.library[i].title,
               reader.library[i].author, reader.library[i].price, reader.library[i].pages);
    }
}

int main() {
    EbookReader my_reader = { .num_books = 0 };

    add_book(&my_reader, (Book) {
            .title = "The Hitchhiker's Guide to the Galaxy",
            .author = "Douglas Adams",
            .price = 12.99,
            .pages = 208
    });

    add_book(&my_reader, (Book) {
            .title = "Harry Potter and the Sorcerer's Stone",
            .author = "J.K. Rowling",
            .price = 8.99,
            .pages = 309
    });

    add_book(&my_reader, (Book) {
            .title = "The Lord of the Rings",
            .author = "J.R.R. Tolkien",
            .price = 17.49,
            .pages = 1178
    });

    printf("Your Ebook Reader contains %d books:\n", my_reader.num_books);
    print_books(my_reader);

    return 0;
}
//FormAI DATASET v1.0 Category: Browser Plugin ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Book {
    char title[100];
    int pages;
    float rating;
} Book;

bool should_display_book(Book* book, float min_rating, int max_pages) {
    return book->rating >= min_rating && book->pages <= max_pages;
}

void display_books(Book* books, int num_books, float min_rating, int max_pages) {
    for (int i = 0; i < num_books; i++) {
        if (should_display_book(&books[i], min_rating, max_pages)) {
            printf("%s\n", books[i].title);
        }
    }
}

int main() {
    Book books[5];

    // Populate the array with some sample books
    strcpy(books[0].title, "Harry Potter and the Philosopher's Stone");
    books[0].pages = 223;
    books[0].rating = 4.5;

    strcpy(books[1].title, "To Kill a Mockingbird");
    books[1].pages = 281;
    books[1].rating = 4.4;

    strcpy(books[2].title, "The Catcher in the Rye");
    books[2].pages = 277;
    books[2].rating = 4.0;

    strcpy(books[3].title, "Pride and Prejudice");
    books[3].pages = 279;
    books[3].rating = 4.3;

    strcpy(books[4].title, "1984");
    books[4].pages = 328;
    books[4].rating = 4.5;

    // Display the books with a minimum rating of 4.3 and maximum of 300 pages
    display_books(books, 5, 4.3, 300);

    return 0;
}
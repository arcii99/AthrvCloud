//FormAI DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_PAGES 1000

struct Book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char* content[MAX_PAGES];
};

struct EbookReader {
    int num_books;
    struct Book library[MAX_BOOKS];
    int current_book;
    int current_page;
};

void addBookToLibrary(struct EbookReader* reader, char* title, char* author, int pages) {
    if (reader->num_books >= MAX_BOOKS) {
        printf("Library is full. Cannot add book.\n");
        return;
    }

    struct Book new_book;
    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    new_book.pages = pages;
    for (int i = 0; i < pages; i++) {
        new_book.content[i] = malloc(MAX_PAGES * sizeof(char));
    }

    reader->library[reader->num_books] = new_book;
    reader->num_books++;
}

void setCurrentBook(struct EbookReader* reader, char* title) {
    int i;
    for (i = 0; i < reader->num_books; i++) {
        if (strcmp(reader->library[i].title, title) == 0) {
            reader->current_book = i;
            reader->current_page = 0;
            return;
        }
    }
    printf("Book not found in library.\n");
}

void showCurrentPage(struct EbookReader* reader) {
    printf("%s by %s\n", reader->library[reader->current_book].title, reader->library[reader->current_book].author);
    printf("Page %d:\n%s\n", reader->current_page+1, reader->library[reader->current_book].content[reader->current_page]);
}

void previousPage(struct EbookReader* reader) {
    if (reader->current_page == 0) {
        printf("Already at beginning of book.\n");
        return;
    }
    reader->current_page--;
}

void nextPage(struct EbookReader* reader) {
    if (reader->current_page == reader->library[reader->current_book].pages - 1) {
        printf("Already at end of book.\n");
        return;
    }
    reader->current_page++;
}

void closeReader(struct EbookReader* reader) {
    for (int i = 0; i < reader->num_books; i++) {
        for (int j = 0; j < reader->library[i].pages; j++) {
            free(reader->library[i].content[j]);
        }
    }
}

int main() {
    struct EbookReader reader;
    reader.num_books = 0;
    reader.current_book = -1;
    reader.current_page = -1;

    // Add some books to the library
    addBookToLibrary(&reader, "The Great Gatsby", "F. Scott Fitzgerald", 180);
    for (int i = 0; i < reader.library[0].pages; i++) {
        sprintf(reader.library[0].content[i], "This is page %d of The Great Gatsby.", i+1);
    }

    addBookToLibrary(&reader, "To Kill a Mockingbird", "Harper Lee", 200);
    for (int i = 0; i < reader.library[1].pages; i++) {
        sprintf(reader.library[1].content[i], "This is page %d of To Kill a Mockingbird.", i+1);
    }

    // Set the current book to To Kill a Mockingbird
    setCurrentBook(&reader, "To Kill a Mockingbird");

    // Show the current page
    showCurrentPage(&reader);

    // Move to the next page
    nextPage(&reader);

    // Show the current page again
    showCurrentPage(&reader);

    // Move back to the previous page
    previousPage(&reader);

    // Show the current page again
    showCurrentPage(&reader);

    // Close the reader and free memory
    closeReader(&reader);

    return 0;
}
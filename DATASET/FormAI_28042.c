//FormAI DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <string.h>

// define the book structure
typedef struct {
    char title[50];
    char author[50];
    int pages;
} Book;

// define the ebook structure
typedef struct {
    Book book;
    char* file_path;
    int current_page;
} Ebook;

// function to open the ebook and set the current page to the beginning
void open_ebook(Ebook* ebook) {
    printf("Opening %s by %s...\n", ebook->book.title, ebook->book.author);
    ebook->current_page = 1;
}

// function to turn to the next page of the ebook
void next_page(Ebook* ebook) {
    if (ebook->current_page + 1 > ebook->book.pages) {
        printf("You have reached the end of the book!\n");
    } else {
        ebook->current_page++;
        printf("Turning to page %d...\n", ebook->current_page);
    }
}

// function to turn to the previous page of the ebook
void prev_page(Ebook* ebook) {
    if (ebook->current_page - 1 < 1) {
        printf("You are already at the beginning of the book!\n");
    } else {
        ebook->current_page--;
        printf("Turning to page %d...\n", ebook->current_page);
    }
}

int main() {
    // create a sample ebook
    Ebook ebook = {
        .book = {
            .title = "The Hitchhiker's Guide to the Galaxy",
            .author = "Douglas Adams",
            .pages = 193
        },
        .file_path = "/path/to/ebook.pdf",
        .current_page = 1
    };

    // open the ebook
    open_ebook(&ebook);

    // turn to the next page
    next_page(&ebook);

    // turn to the previous page
    prev_page(&ebook);

    return 0;
}
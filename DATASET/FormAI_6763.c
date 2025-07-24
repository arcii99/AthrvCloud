//FormAI DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_BOOK_TITLE_LENGTH 100
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    int num_pages;
    char page_contents[MAX_PAGES][1000]; // each page can contain up to 1000 characters
} Book;

void read_book(Book* book, char* file_name) {
    // read the book from file and store the data in the Book structure
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", file_name);
        return;
    }
    fgets(book->title, MAX_BOOK_TITLE_LENGTH, fp); // read the book title
    fscanf(fp, "%d", &book->num_pages); // read the number of pages
    for (int i = 0; i < book->num_pages; i++) {
        fgets(book->page_contents[i], 1000, fp); // read each page's contents
    }
    fclose(fp);
}

void display_page(Book* book, int page_num) {
    // display the given page number of the book
    if (page_num < 0 || page_num >= book->num_pages) {
        printf("Error: page number out of range\n");
        return;
    }
    printf("Page %d of %d\n\n", page_num + 1, book->num_pages);
    printf("%s\n", book->page_contents[page_num]);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the book file: ");
    scanf("%s", file_name);
    Book book;
    read_book(&book, file_name);
    printf("The book \"%s\" has %d pages.\n", book.title, book.num_pages);
    int current_page = 0;
    bool quit = false;
    while (!quit) {
        display_page(&book, current_page);
        printf("Press <Enter> to go to the next page, or Q to quit: ");
        char input[10];
        scanf("%s", input);
        if (input[0] == 'Q' || input[0] == 'q') {
            quit = true;
        } else {
            current_page++;
            if (current_page >= book.num_pages) {
                printf("End of book.\n");
                quit = true;
            }
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_PAGES 100
#define MAX_PAGE_LENGTH 1000

struct ebook {
    char title[50];
    char author[50];
    char pages[MAX_PAGES][MAX_PAGE_LENGTH];
    int current_page;
    int total_pages;
};

void print_current_page(struct ebook *book) {
    printf("%s\n\n", book->title);
    printf("Author: %s\n", book->author);
    printf("%s\n", book->pages[book->current_page]);
    printf("Page %d of %d\n", book->current_page + 1, book->total_pages);
}

void next_page(struct ebook *book) {
    if (book->current_page + 1 < book->total_pages) {
        book->current_page++;
        print_current_page(book);
    } else {
        printf("You have reached the end of the book.\n");
    }
}

void previous_page(struct ebook *book) {
    if (book->current_page > 0) {
        book->current_page--;
        print_current_page(book);
    } else {
        printf("You are already on the first page.\n");
    }
}

void goto_page(struct ebook *book, int page_number) {
    if (page_number >= 1 && page_number <= book->total_pages) {
        book->current_page = page_number - 1;
        print_current_page(book);
    } else {
        printf("Invalid page number.\n");
    }
}

int main() {
    struct ebook book;
    strcpy(book.title, "The Hitchhiker's Guide to the Galaxy");
    strcpy(book.author, "Douglas Adams");

    strcpy(book.pages[0], "The story so far:\n");
    strcpy(book.pages[1], "In the beginning the Universe was created.\n");
    strcpy(book.pages[2], "This has made a lot of people very angry and been widely regarded as a bad move.\n");
    book.total_pages = 3;
    book.current_page = 0;

    print_current_page(&book);

    char input[10];
    while(1) {
        printf("Enter a command (next, prev, goto, quit): ");
        scanf("%s", input);

        if (strcmp(input, "next") == 0) {
            next_page(&book);
        } else if (strcmp(input, "prev") == 0) {
            previous_page(&book);
        } else if (strcmp(input, "goto") == 0) {
            printf("Enter page number: ");
            int page_number;
            scanf("%d", &page_number);
            goto_page(&book, page_number);
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
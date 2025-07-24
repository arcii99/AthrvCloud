//FormAI DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct page {
    char content[1000];
};

// function to read the contents of the ebook
void read_book(struct page *book) {
    printf("Reading book...\n");
    FILE *fp = fopen("book.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int i = 0;
    while (fgets(book[i].content, sizeof(book[i].content), fp) != NULL) {
        i++;
    }

    fclose(fp);
}

// function to display a page of the ebook
void display_page(int page_number, struct page *book) {
    printf("Page %d:\n", page_number);
    printf("%s\n", book[page_number-1].content);
}

int main() {
    printf("Welcome to the Ebook Reader!\n");

    // create book
    struct page book[50];

    // read book
    read_book(book);

    // display page 1
    display_page(1, book);

    // display next page
    int page_number = 2;
    char input;
    while (1) {
        printf("Press 'n' for next page or 'q' to quit.\n");
        scanf(" %c", &input);
        if (input == 'n') {
            if (page_number <= 50) {
                display_page(page_number, book);
                page_number++;
            } else {
                printf("You have reached the end of the book!\n");
                break;
            }
        } else if (input == 'q') {
            break;
        } else {
            printf("Invalid input.\n");
        }
    }
    printf("Thank you for using the Ebook Reader!\n");

    return 0;
}
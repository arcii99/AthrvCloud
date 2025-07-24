//FormAI DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 10
#define MAX_PAGES 100

typedef struct {
    char title[50];
    char author[50];
    char content[MAX_PAGES][1000];
    int current_page;
    int num_pages;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int num_books;
} Library;

int main() {
    Library library;
    int choice, book_index, page_number;
    char buffer[1000];

    while (1) {
        printf("\nEnter a choice:\n");
        printf("1. Add new book\n");
        printf("2. Read book\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (library.num_books < MAX_BOOKS) {
                    printf("Enter book title: ");
                    scanf("%s", library.books[library.num_books].title);

                    printf("Enter book author: ");
                    scanf("%s", library.books[library.num_books].author);

                    printf("Enter book content (type END to finish):\n");
                    library.books[library.num_books].num_pages = 0;
                    while (1) {
                        scanf("%s", buffer);
                        if (strcmp(buffer, "END") == 0) {
                            break;
                        }
                        strcpy(library.books[library.num_books].content[library.books[library.num_books].num_pages++], buffer);
                    }
                    library.num_books++;
                }
                else {
                    printf("Maximum number of books reached.\n");
                }
                break;
            case 2:
                printf("Enter book index (0 to %d): ", library.num_books - 1);
                scanf("%d", &book_index);

                if (book_index < 0 || book_index >= library.num_books) {
                    printf("Invalid book index.\n");
                }
                else {
                    printf("%s by %s\n", library.books[book_index].title, library.books[book_index].author);

                    while (1) {
                        printf("\nEnter page number (1 to %d, or 0 to exit): ", library.books[book_index].num_pages);

                        scanf("%d", &page_number);

                        if (page_number < 0 || page_number > library.books[book_index].num_pages) {
                            printf("Invalid page number.\n");
                        }
                        else if (page_number == 0) {
                            break;
                        }
                        else {
                            printf("%s\n", library.books[book_index].content[page_number - 1]);
                            library.books[book_index].current_page = page_number - 1;
                        }
                    }
                }

                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
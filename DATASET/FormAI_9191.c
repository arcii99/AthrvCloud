//FormAI DATASET v1.0 Category: Ebook reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_PAGES 1000
#define PAGE_SIZE 50

typedef struct {
    char title[100];
    char author[100];
    char pages[MAX_PAGES][PAGE_SIZE];
    int num_pages;
} Book;

int num_books = 0;
Book books[MAX_BOOKS];

void load_book(char* file_name);
void display_menu();

int main() {
    char input[100];

    display_menu();

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "load") == 0) {
            char file_name[100];
            printf("Enter file name: ");
            scanf("%s", file_name);
            load_book(file_name);
        } else if (strcmp(input, "list") == 0) {
            printf("\n=== Available Books ===\n");
            for (int i = 0; i < num_books; i++) {
                printf("%s by %s (%d pages)\n", books[i].title, books[i].author, books[i].num_pages);
            }
        } else if (strcmp(input, "read") == 0) {
            int book_index;
            printf("Enter book number: ");
            scanf("%d", &book_index);

            if (book_index < 1 || book_index > num_books) {
                printf("Invalid book number.\n");
            } else {
                Book* book = &books[book_index - 1];

                printf("\n=== %s ===\n", book->title);
                for (int i = 0; i < book->num_pages; i++) {
                    printf("%s\n", book->pages[i]);
                }
            }
        } else {
            printf("Invalid command.\n");
            display_menu();
        }
    }

    return 0;
}

void load_book(char* file_name) {
    FILE* file = fopen(file_name, "r");
    char* line = malloc(sizeof(char) * PAGE_SIZE);

    if (file == NULL) {
        printf("Could not open file: %s\n", file_name);
    } else {
        Book* book = &books[num_books];

        fscanf(file, "%[^\n]\n", book->title);
        fscanf(file, "%[^\n]\n", book->author);

        while (fgets(line, PAGE_SIZE, file)) {
            if (strlen(line) == PAGE_SIZE - 1 && line[PAGE_SIZE - 2] != '\n') {
                printf("Page too long: %s\n", line);
                break;
            } else {
                strcpy(book->pages[book->num_pages], line);
                book->num_pages++;
            }
        }

        fclose(file);
        free(line);

        printf("Book loaded: %s by %s (%d pages)\n", book->title, book->author, book->num_pages);

        if (num_books < MAX_BOOKS) {
            num_books++;
        } else {
            printf("Maximum number of books reached.\n");
        }
    }
}

void display_menu() {
    printf("\n=== Ebook Reader ===\n");
    printf("Available commands:\n");
    printf("load - load a book from a text file\n");
    printf("list - list available books\n");
    printf("read - read a book\n");
    printf("exit - exit the program\n");
}
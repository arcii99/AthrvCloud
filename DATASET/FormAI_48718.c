//FormAI DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_BOOK_TITLE 50

typedef struct {
    char title[MAX_BOOK_TITLE];
    int size;
    char* content;
} Book;

Book* load_book(char* file_name) {
    FILE* fp;
    Book* book;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", file_name);
        return NULL;
    }

    book = (Book*)malloc(sizeof(Book));
    if (book == NULL) {
        printf("Could not allocate memory for book\n");
        fclose(fp);
        return NULL;
    }

    strcpy(book->title, file_name);
    fseek(fp, 0L, SEEK_END);
    book->size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    book->content = (char*)malloc(book->size * sizeof(char));
    if (book->content == NULL) {
        printf("Could not allocate memory for book content\n");
        free(book);
        fclose(fp);
        return NULL;
    }

    fread(book->content, sizeof(char), book->size, fp);

    fclose(fp);

    return book;
}

void display_book(Book* book) {
    printf("Title: %s\n", book->title);
    printf("Size: %d\n", book->size);
    printf("Content: %s\n", book->content);
}

int main() {
    char file_name[MAX_FILE_NAME];
    Book* book;

    printf("Enter the name of the ebook file: ");
    fgets(file_name, MAX_FILE_NAME, stdin);
    // Remove newline character from file name
    file_name[strcspn(file_name, "\n")] = 0;

    book = load_book(file_name);
    if (book == NULL) {
        exit(EXIT_FAILURE);
    }

    display_book(book);

    free(book->content);
    free(book);

    return 0;
}
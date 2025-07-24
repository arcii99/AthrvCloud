//FormAI DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_FILENAME_LENGTH 50

typedef struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char *content;
} Book;

typedef struct ebook_reader {
    int num_books;
    Book *library[MAX_BOOKS];
} Ebook_Reader;

int add_book(Ebook_Reader *reader, char *title, char *author, char *filename);
void display_library(Ebook_Reader *reader);
void read_book(Ebook_Reader *reader, int book_index);
void free_library(Ebook_Reader *reader);

int main() {
    Ebook_Reader my_reader;
    my_reader.num_books = 0;
    int choice;
    char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH], filename[MAX_FILENAME_LENGTH];

    while (1) {
        printf("Choose an option: \n1. Add book\n2. Display library\n3. Read book\n4. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the book title: ");
                scanf("%s", title);
                printf("Enter the author name: ");
                scanf("%s", author);
                printf("Enter the filename: ");
                scanf("%s", filename);
                if (add_book(&my_reader, title, author, filename)) {
                    printf("Book added successfully!\n");
                } else {
                    printf("Failed to add book!\n");
                }
                break;
            case 2:
                display_library(&my_reader);
                break;
            case 3:
                int index;
                printf("Enter the book index to read: ");
                scanf("%d", &index);
                read_book(&my_reader, index);
                break;
            case 4:
                free_library(&my_reader);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
}

int add_book(Ebook_Reader *reader, char *title, char *author, char *filename) {
    if (reader->num_books >= MAX_BOOKS) {
        return 0;
    }

    Book *new_book = malloc(sizeof(Book));
    if (new_book == NULL) {
        return 0;
    }

    strcpy(new_book->title, title);
    strcpy(new_book->author, author);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        free(new_book);
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    new_book->content = malloc(fsize + 1);
    if (new_book->content == NULL) {
        free(new_book);
        fclose(fp);
        return 0;
    }

    fread(new_book->content, 1, fsize, fp);
    fclose(fp);
    new_book->content[fsize] = '\0';

    reader->library[reader->num_books] = new_book;
    reader->num_books++;

    return 1;
}

void display_library(Ebook_Reader *reader) {
    if (reader->num_books == 0) {
        printf("Library is empty.\n");
        return;
    }

    for (int i = 0; i < reader->num_books; i++) {
        printf("%d. %s by %s\n", i, reader->library[i]->title, reader->library[i]->author);
    }
}

void read_book(Ebook_Reader *reader, int book_index) {
    if (book_index < 0 || book_index >= reader->num_books) {
        printf("Invalid book index.\n");
        return;
    }

    printf("Reading %s by %s\n", reader->library[book_index]->title, reader->library[book_index]->author);
    printf("%s", reader->library[book_index]->content);
}

void free_library(Ebook_Reader *reader) {
    for (int i = 0; i < reader->num_books; i++) {
        free(reader->library[i]->content);
        free(reader->library[i]);
    }
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 10

struct book {
    char title[100];
    char author[100];
    char filename[100];
    bool is_encrypted;
};

struct book library[MAX_BOOKS];
int num_books = 0;

void read_book_file(char *filename, char *buffer);
bool is_encrypted(char *file_contents);
void decrypt(char *file_contents);
void print_book(struct book b);

int main() {
    char book_buffer[10000];

    // Read in all the book files and populate the library array
    read_book_file("book1.txt", book_buffer);
    library[0].is_encrypted = is_encrypted(book_buffer);
    strcpy(library[0].title, "Book 1");
    strcpy(library[0].author, "Author 1");
    strcpy(library[0].filename, "book1.txt");
    if (library[0].is_encrypted) {
        decrypt(book_buffer);
    }

    read_book_file("book2.txt", book_buffer);
    library[1].is_encrypted = is_encrypted(book_buffer);
    strcpy(library[1].title, "Book 2");
    strcpy(library[1].author, "Author 2");
    strcpy(library[1].filename, "book2.txt");
    if (library[1].is_encrypted) {
        decrypt(book_buffer);
    }

    // Display the library with paranoid book titles
    for (int i = 0; i < num_books; i++) {
        struct book b = library[i];
        char paranoid_title[100];
        memset(paranoid_title, '\0', sizeof(paranoid_title));

        for (int j = 0; j < strlen(b.title); j++) {
            int ascii_value = (int) b.title[j];
            if (ascii_value >= 97 && ascii_value <= 122) {
                // Lowercase letter
                ascii_value = 122 - (ascii_value - 97);
            } else if (ascii_value >= 65 && ascii_value <= 90) {
                // Uppercase letter
                ascii_value = 90 - (ascii_value - 65);
            }
            paranoid_title[j] = (char) ascii_value;
        }

        printf("Book #%d: %s by %s\n", i, paranoid_title, b.author);
    }

    return 0;
}

void read_book_file(char *filename, char *buffer) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read in the file contents
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF && i < sizeof(buffer)) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    fclose(fp);
}

bool is_encrypted(char *file_contents) {
    // Check if the file contents contain the string "ENCRYPTED"
    return (strstr(file_contents, "ENCRYPTED") != NULL);
}

void decrypt(char *file_contents) {
    // Decrypt the file contents
    for (int i = 0; i < strlen(file_contents); i++) {
        int ascii_value = (int) file_contents[i];
        if (ascii_value >= 65 && ascii_value <= 90) {
            // Uppercase letter
            if (ascii_value == 65) {
                ascii_value = 90;
            } else {
                ascii_value--;
            }
        } else if (ascii_value >= 97 && ascii_value <= 122) {
            // Lowercase letter
            if (ascii_value == 97) {
                ascii_value = 122;
            } else {
                ascii_value--;
            }
        }
        file_contents[i] = (char) ascii_value;
    }
}

void print_book(struct book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Filename: %s\n", b.filename);
    printf("Is Encrypted: %s\n", b.is_encrypted ? "YES" : "NO");
}
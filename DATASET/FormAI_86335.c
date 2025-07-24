//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char author[50];
    char title[50];
    char description[100];
    int year_published;
    float price;
} Book;

void parse_metadata(char* filename, Book* book) {
    FILE* file = fopen(filename, "r");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, "\n");
        if (strcmp(key, "Author") == 0) {
            strcpy(book->author, value);
        }
        else if (strcmp(key, "Title") == 0) {
            strcpy(book->title, value);
        }
        else if (strcmp(key, "Description") == 0) {
            strcpy(book->description, value);
        }
        else if (strcmp(key, "Year Published") == 0) {
            book->year_published = atoi(value);
        }
        else if (strcmp(key, "Price") == 0) {
            book->price = atof(value);
        }
    }
    fclose(file);
}

int main() {
    Book book;
    char filename[] = "book_metadata.txt";
    parse_metadata(filename, &book);
    printf("Author: %s\n", book.author);
    printf("Title: %s\n", book.title);
    printf("Description: %s\n", book.description);
    printf("Year Published: %d\n", book.year_published);
    printf("Price: %.2f\n", book.price);
    return 0;
}
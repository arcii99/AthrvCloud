//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char author[50];
    char title[100];
    char year[5];
} Book;

int main()
{
    FILE *file;
    char *filename = "book_metadata.txt"; // The filename
    Book book;

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Unable to open file"); // print error message if file not found
        exit(1);
    }

    while (fscanf(file, "%[^\n]\n", &book.title) == 1) { // read line by line until end of file
        fscanf(file, "%[^\n]\n", &book.author);
        fscanf(file, "%[^\n]\n", &book.year);

        printf("Title: %s\n", book.title);
        printf("Author: %s\n", book.author);
        printf("Year: %s\n", book.year);
        printf("------------------------\n");
    }

    fclose(file); // close the file

    return 0;
}
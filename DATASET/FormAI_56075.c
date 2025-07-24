//FormAI DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    char author[50];
    int pages;
};

int main() {
    struct book ebook;
    FILE *file;
    char *filename = "ebook.txt";
    char line[100];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    // Read book information from file
    fgets(line, 100, file);
    sscanf(line, "%[^,],%[^,],%d", ebook.title, ebook.author, &ebook.pages);

    // Display book information
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Pages: %d\n", ebook.pages);
    
    fclose(file);
    return 0;
}
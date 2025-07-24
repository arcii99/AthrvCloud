//FormAI DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} Ebook;

void printEbook(Ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Content:\n%s\n", ebook.content);
}

Ebook loadEbook(char* fileName) {
    Ebook ebook;
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not load ebook from file %s\n", fileName);
        exit(1);
    }
    fscanf(file, "%[^\n]\n", ebook.title);
    fscanf(file, "%[^\n]\n", ebook.content);
    fclose(file);
    return ebook;
}

int main() {
    Ebook ebook = loadEbook("myebook.txt");
    printEbook(ebook);
    return 0;
}
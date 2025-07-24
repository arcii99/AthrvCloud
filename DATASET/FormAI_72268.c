//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int page_number;
    char* content;
} Page;

/* Function to read a page from a file */
Page read_page(FILE* fp, int page_number) {
    int content_size = 1024;
    char* content = (char*) malloc(content_size * sizeof(char));
    int c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\f') {
            break;
        }
        content[i++] = (char) c;
        if (i == content_size) {
            content_size *= 2;
            content = (char*) realloc(content, content_size * sizeof(char));
        }
    }
    content[i] = '\0';
    Page page = {page_number, content};
    return page;
}

int main() {
    char* filename = "book.txt";
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return 1;
    }
    int current_page = 1;
    Page page = read_page(fp, current_page);
    printf("Page %d:\n%s\n", page.page_number, page.content);
    fclose(fp);
    free(page.content);
    return 0;
}
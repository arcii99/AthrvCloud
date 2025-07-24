//FormAI DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ebook {
    char title[100];
    char author[100];
    char format[10];
    int pages;
    char filename[100];
};

void read_ebook(struct ebook book) {
    FILE *fp;
    fp = fopen(book.filename, "r");
    if (fp == NULL) {
        printf("Error Reading File\n");
        return;
    }
    char line[100];
    printf("\n%s by %s\n\n", book.title, book.author);
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

int main() {
    struct ebook mybook;
    strcpy(mybook.title, "The C Programming Language");
    strcpy(mybook.author, "Brian W. Kernighan and Dennis M. Ritchie");
    strcpy(mybook.format, "PDF");
    mybook.pages = 288;
    strcpy(mybook.filename, "c_book.pdf");

    read_ebook(mybook);

    return 0;
}
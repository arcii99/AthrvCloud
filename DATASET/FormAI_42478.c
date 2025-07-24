//FormAI DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ebook {
    char title[100];
    char author[100];
    char genre[50];
    int pages;
    char format[20];
    char filename[100];
} Ebook;

typedef struct EbookReader {
    Ebook* ebook;
    int progress;
    int currentPage;
    int totalPages;
} EbookReader;

void printEbookDetails(Ebook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Genre: %s\n", ebook->genre);
    printf("Pages: %d\n", ebook->pages);
    printf("Format: %s\n", ebook->format);
}

void readEbook(EbookReader* reader) {
    printf("Opening ebook %s...\n", reader->ebook->filename);
    printf("You are on page %d of %d.\n", reader->currentPage, reader->totalPages);
    printf("Press enter to turn page.");
    getchar();
    reader->currentPage++;
}

int main() {
    Ebook ebook1 = {
        .title = "The Great Gatsby",
        .author = "F. Scott Fitzgerald",
        .genre = "Novel",
        .pages = 180,
        .format = "EPUB",
        .filename = "gatsby.epub"
    };

    EbookReader reader = {
        .ebook = &ebook1,
        .progress = 0,
        .currentPage = 1,
        .totalPages = ebook1.pages
    };

    printEbookDetails(&ebook1);

    while (reader.currentPage <= reader.totalPages) {
        readEbook(&reader);
    }

    printf("You have finished reading %s!\n", ebook1.title);

    return 0;
}
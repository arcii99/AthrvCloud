//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LEN 50
#define MAX_FILENAME_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_TITLE_LEN];
    char filename[MAX_FILENAME_LEN];
} Book;

Book catalogue[MAX_BOOKS];
int numBooks = 0;

void addBook(char title[], char author[], char filename[]) {
    if (numBooks == MAX_BOOKS) {
        printf("Catalogue is full!\n");
        return;
    }
    strcpy(catalogue[numBooks].title, title);
    strcpy(catalogue[numBooks].author, author);
    strcpy(catalogue[numBooks].filename, filename);
    numBooks++;
}

void displayCatalogue() {
    if (numBooks == 0) {
        printf("Catalogue is empty!\n");
        return;
    }
    printf("Catalogue:\n\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s\n", i + 1, catalogue[i].title, catalogue[i].author);
    }
}

void readBook(char filename[]) {
    printf("Reading book: %s\n", filename);
    // code to read ebook file goes here
}

int main() {
    addBook("The Catcher in the Rye", "J.D. Salinger", "catcher_in_the_rye.epub");
    addBook("To Kill a Mockingbird", "Harper Lee", "to_kill_a_mockingbird.mobi");
    addBook("1984", "George Orwell", "1984.pdf");
    displayCatalogue();
    readBook("catcher_in_the_rye.epub");
    return 0;
}
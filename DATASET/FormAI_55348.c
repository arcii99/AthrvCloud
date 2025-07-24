//FormAI DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ebook {
    char title[50];
    char author[50];
    int pages;
    char content[1000];
} Ebook;

void readEbook(Ebook book) {
    printf("\nTitle: %s", book.title);
    printf("\nAuthor: %s", book.author);
    printf("\nNumber of Pages: %d", book.pages);
    printf("\nContent: %s", book.content);
}

void openEbook(char *filename, Ebook *book) {
    FILE *fp;
    char ch;
    int i = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error Opening File.");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        book->content[i++] = ch;
    }
    fclose(fp);
}

int main() {
    Ebook book1;
    strcpy(book1.title, "The Catcher in the Rye");
    strcpy(book1.author, "J.D. Salinger");
    book1.pages = 224;
    openEbook("catcher_in_the_rye.txt", &book1);
    readEbook(book1);

    Ebook book2;
    strcpy(book2.title, "To Kill a Mockingbird");
    strcpy(book2.author, "Harper Lee");
    book2.pages = 281;
    openEbook("to_kill_a_mockingbird.txt", &book2);
    readEbook(book2);

    return 0;
}
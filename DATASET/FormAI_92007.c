//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ebook {
   char title[50];
   char author[50];
   int year;
};

void readEbook(struct Ebook* eBook) {
    printf("Enter the book title: ");
    scanf("%s", &eBook->title);
    printf("Enter the author: ");
    scanf("%s", &eBook->author);
    printf("Enter the year the book was published: ");
    scanf("%d", &eBook->year);
}

void displayEbook(struct Ebook eBook) {
    printf("Book title: %s\n", eBook.title);
    printf("Author: %s\n", eBook.author);
    printf("Year of publication: %d\n", eBook.year);
}

int main() {
    struct Ebook myEbook;
    readEbook(&myEbook);
    displayEbook(myEbook);
    printf("%s", "This looks like the perfect Ebook reader program!");
    return 0;
}
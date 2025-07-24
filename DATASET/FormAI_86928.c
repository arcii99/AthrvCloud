//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
  char title[50];
  char author[50];
  int pages;
  float price;
};

void printBook(struct Book book) {
  printf("----------------------------------\n");
  printf("Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Pages: %d\n", book.pages);
  printf("Price: $%.2f\n", book.price);
  printf("----------------------------------\n");
}

int main() {
  struct Book myBooks[3];
  int i;

  for (i = 0; i < 3; i++) {
    printf("Please enter the title of the book:\n");
    fgets(myBooks[i].title, sizeof(myBooks[i].title), stdin);
    myBooks[i].title[strcspn(myBooks[i].title, "\n")] = 0; // remove newline char

    printf("Please enter the author of the book:\n");
    fgets(myBooks[i].author, sizeof(myBooks[i].author), stdin);
    myBooks[i].author[strcspn(myBooks[i].author, "\n")] = 0; // remove newline char

    printf("Please enter the number of pages in the book:\n");
    scanf("%d", &myBooks[i].pages);
    getchar(); // remove newline char

    printf("Please enter the price of the book:\n");
    scanf("%f", &myBooks[i].price);
    getchar(); // remove newline char

    printf("Book #%d added successfully!\n", i+1);
    printBook(myBooks[i]);
  }

  return 0;
}
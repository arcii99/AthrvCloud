//FormAI DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
  char title[50];
  char author[50];
  float price;
  int pages;
  char publisher[50];
};

int main() {
  struct book my_book;
  char fileName[50];
  FILE* filePtr;

  printf("Enter name of file to read: ");
  scanf("%s", fileName);

  filePtr = fopen(fileName, "rb");
  if (filePtr == NULL) {
    printf("Error opening file %s\n", fileName);
    return 1;
  }

  printf("Book information:\n");
  while (fread(&my_book, sizeof(struct book), 1, filePtr)) {
    printf("Title: %s\n", my_book.title);
    printf("Author: %s\n", my_book.author);
    printf("Price: $%.2f\n", my_book.price);
    printf("Pages: %d\n", my_book.pages);
    printf("Publisher: %s\n\n", my_book.publisher);
  }

  fclose(filePtr);
  return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
  char title[50];
  char author[50];
  int pages;
  char format[10];
  char path[100];
};

void displayBook(struct Book book) {
  printf("Title: %s\nAuthor: %s\nNumber of Pages: %d\nFormat: %s\nPath: %s\n", book.title, book.author, book.pages, book.format, book.path);
}

void readFile(struct Book book) {
  FILE *fp;
  char ch;
  fp = fopen(book.path, "r");
  if (fp == NULL) {
      printf("Error while opening the file.\n");
      exit(0);
  }
  printf("Contents of file:\n");
  while((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }
  fclose(fp);
}

int main() {
  struct Book book;
  strcpy(book.title, "The C Programming Language");
  strcpy(book.author, "Brian W. Kernighan and Dennis M. Ritchie");
  book.pages = 300;
  strcpy(book.format, "PDF");
  strcpy(book.path, "c_programming_language.pdf");
  displayBook(book);
  readFile(book);
  return 0;
}
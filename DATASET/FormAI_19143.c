//FormAI DATASET v1.0 Category: Ebook reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
};

void displayBook(struct Book book);

int main() {

  struct Book book1;
  struct Book book2;

  strcpy(book1.title, "The C Programming Language");
  strcpy(book1.author, "Brian W. Kernighan and Dennis M. Ritchie");
  strcpy(book1.subject, "Programming");
  book1.book_id = 1;

  strcpy(book2.title, "Effective C++");
  strcpy(book2.author, "Scott Meyers");
  strcpy(book2.subject, "Programming");
  book2.book_id = 2;

  printf("Book 1:\n");
  displayBook(book1);

  printf("\nBook 2:\n");
  displayBook(book2);

  return 0;
}

void displayBook(struct Book book) {
  printf("Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Subject: %s\n", book.subject);
  printf("Book ID: %d\n", book.book_id);
}
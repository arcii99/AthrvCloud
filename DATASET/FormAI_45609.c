//FormAI DATASET v1.0 Category: Ebook reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100

typedef struct {
  char title[50];
  char author[50];
  char publisher[50];
  int year;
} Book;

typedef struct {
  Book books[MAX_BOOKS];
  int numBooks;
} Library;

void addBook(Library *lib, Book book) {
  if (lib->numBooks == MAX_BOOKS) {
    printf("Error: Library is full\n");
    return;
  }
  lib->books[lib->numBooks++] = book;
}

void printBook(Book book) {
  printf("%s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Publisher: %s\n", book.publisher);
  printf("Year: %d\n\n", book.year);
}

void printLibrary(Library *lib) {
  printf("Library contains %d books:\n", lib->numBooks);
  for (int i = 0; i < lib->numBooks; i++) {
    printf("%d. ", i + 1);
    printBook(lib->books[i]);
  }
}

void searchByAuthor(Library *lib, char author[]) {
  for (int i = 0; i < lib->numBooks; i++) {
    if (strcmp(lib->books[i].author, author) == 0) {
      printf("%d. ", i + 1);
      printBook(lib->books[i]);
    }
  }
}

int main() {
  Book b1 = {"The C Programming Language", "Brian Kernighan and Dennis Ritchie", "Prentice Hall", 1978};
  Book b2 = {"Learn C the Hard Way", "Zed A. Shaw", "Addison-Wesley", 2015};
  Book b3 = {"C Programming for the Absolute Beginner", "Michael Vine", "Cengage Learning PTR", 2009};

  Library lib;
  lib.numBooks = 0;

  addBook(&lib, b1);
  addBook(&lib, b2);
  addBook(&lib, b3);

  printLibrary(&lib);

  printf("Books by Brian Kernighan and Dennis Ritchie:\n");
  searchByAuthor(&lib, "Brian Kernighan and Dennis Ritchie");

  return 0;
}
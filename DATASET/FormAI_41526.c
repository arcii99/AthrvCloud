//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <string.h>

typedef struct {
   char title[100];
   char author[100];
   int year;
   int pages;
} Book;

void printBook(Book book) {
   printf("Title: %s\n", book.title);
   printf("Author: %s\n", book.author);
   printf("Year: %d\n", book.year);
   printf("Pages: %d\n", book.pages);
}

int main() {
   Book books[] = {
      {"C Programming Language", "Dennis Ritchie", 1978, 272},
      {"The C Programming Language", "Brian Kernighan", 1988, 274},
      {"C Programming Absolute Beginner's Guide", "Greg Perry and Dean Miller", 2002, 352},
      {"C Programming for the Absolute Beginner, Second Edition", "Michael Vine", 2007, 384},
      {"C Programming for Scientists and Engineers with Applications", "Rama K. Yedavalli", 2012, 386},
      {"Beginning C, Third Edition", "Ivor Horton", 2012, 648},
   };

   int numBooks = 6;

   // Read user input for desired book title
   char input[100];
   printf("Enter book title: ");
   fgets(input, 100, stdin);
   input[strcspn(input, "\n")] = 0; // Remove newline character

   // Search for book with matching title
   int i;
   for (i = 0; i < numBooks; i++) {
      if (strcmp(input, books[i].title) == 0) {
         printBook(books[i]);
         break;
      }
   }

   // If no matching title found, print error message
   if (i == numBooks) {
      printf("Error: Book not found.\n");
   }

   return 0;
}
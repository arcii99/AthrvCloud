//FormAI DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

struct EBook {
   char title[50];
   char author[50];
   char format[10];
   int pages;
};

typedef struct EBook EBook;

void displayBook(EBook book) {
   printf("Title: %s\n", book.title);
   printf("Author: %s\n", book.author);
   printf("Format: %s\n", book.format);
   printf("Pages: %d\n", book.pages);
}

int main() {
   EBook myBook = {"The C Programming Language", "Dennis Ritchie and Brian Kernighan", "PDF", 288};
   
   printf("Welcome to your Ebook Reader!\n");
   
   displayBook(myBook);
   
   int pageNum = 20;
   printf("Jumping to page %d...\n", pageNum);
   
   //code to jump to specified page goes here
   
   printf("Enjoy reading!\n");
   
   return 0;
}
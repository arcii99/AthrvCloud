//FormAI DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct Book {
   char title[50];
   char author[50];
   char genre[20];
   int pageCount;
};

void displayBook(struct Book book) {
   printf("Title: %s\n", book.title);
   printf("Author: %s\n", book.author);
   printf("Genre: %s\n", book.genre);
   printf("Page Count: %d\n\n", book.pageCount);
}

int main() {
   int bookCount;
   printf("How many books do you want to create a collection of? ");
   scanf("%d", &bookCount);
   
   struct Book books[bookCount]; // creating an array of books
   
   for(int i = 0; i < bookCount; i++) {
      // get book information from user
      printf("\n\nEnter details of book %d:\n", i+1);
      printf("Title: ");
      scanf("%s", books[i].title);
      printf("Author: ");
      scanf("%s", books[i].author);
      printf("Genre: ");
      scanf("%s", books[i].genre);
      printf("Page Count: ");
      scanf("%d", &books[i].pageCount);
   }
   
   printf("\n\nYour collection of books:\n\n");
   
   for(int i = 0; i < bookCount; i++) {
      displayBook(books[i]); // display book information
   }
   
   return 0;
}
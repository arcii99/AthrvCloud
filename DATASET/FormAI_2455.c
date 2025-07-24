//FormAI DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
   char title[50];
   char author[50];
   int pages;
   float price;
};

int main () {
   struct Book b1, b2, b3;
   FILE *fp;

   // initialize the books
   strcpy(b1.title, "Introduction to C Programming");
   strcpy(b1.author, "John Smith");
   b1.pages = 300;
   b1.price = 25.99;

   strcpy(b2.title, "Data Structures in C");
   strcpy(b2.author, "Jane Doe");
   b2.pages = 400;
   b2.price = 30.99;

   strcpy(b3.title, "Algorithms and Data Structures");
   strcpy(b3.author, "David Brown");
   b3.pages = 500;
   b3.price = 35.99;

   // write the books to a binary file
   fp = fopen("books.dat", "wb");
   if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
   }
   fwrite(&b1, sizeof(struct Book), 1, fp);
   fwrite(&b2, sizeof(struct Book), 1, fp);
   fwrite(&b3, sizeof(struct Book), 1, fp);
   fclose(fp);

   // read the books from the binary file
   fp = fopen("books.dat", "rb");
   if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
   }
   printf("Reading books...\n");
   fread(&b1, sizeof(struct Book), 1, fp);
   printf("Book 1 - Title: %s, Author: %s, Pages: %d, Price: $%.2f\n", b1.title, b1.author, b1.pages, b1.price);

   fread(&b2, sizeof(struct Book), 1, fp);
   printf("Book 2 - Title: %s, Author: %s, Pages: %d, Price: $%.2f\n", b2.title, b2.author, b2.pages, b2.price);

   fread(&b3, sizeof(struct Book), 1, fp);
   printf("Book 3 - Title: %s, Author: %s, Pages: %d, Price: $%.2f\n", b3.title, b3.author, b3.pages, b3.price);

   fclose(fp);
   
   return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <string.h>

// Structure to hold eBook properties
struct eBook {
   char title[50];
   char author[50];
   int pageCount;
   float price;
   char format[10];
   char ebookFile[100];
};

int main() {
   struct eBook book1;
   strcpy(book1.title, "The C Programming Language");
   strcpy(book1.author, "Brian W. Kernighan, Dennis M. Ritchie");
   book1.pageCount = 274;
   book1.price = 12.99;
   strcpy(book1.format, "PDF");
   strcpy(book1.ebookFile, "c-programming.pdf");

   printf("Title: %s\n", book1.title);
   printf("Author: %s\n", book1.author);
   printf("Pages: %d\n", book1.pageCount);
   printf("Price: $%f\n", book1.price);
   printf("Format: %s\n", book1.format);
   printf("File: %s\n", book1.ebookFile);

   printf("\nOpening %s...\n", book1.ebookFile);

   // Open the eBook file and display its contents
   FILE *fptr = fopen(book1.ebookFile, "r");

   if (fptr == NULL) {
      printf("Error opening file.\n");
      return 1;
   }

   // Read and display each page of the eBook
   int page = 1;
   int c;
   printf("\n--- PAGE %d ---\n", page);

   while ((c = fgetc(fptr)) != EOF) {
      putchar(c);
      if (c == '\n') {
         printf("--- PAGE %d ---\n", ++page);
      }
   }

   fclose(fptr);
   return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

typedef struct Book {
   char title[50];
   char author[50];
   int pages;
   float price;
} Book;

int main() {
   Book book1;
   printf("Enter the book title: ");
   fgets(book1.title, sizeof(book1.title), stdin);
   printf("Enter the author name: ");
   fgets(book1.author, sizeof(book1.author), stdin);
   printf("Enter the number of pages: ");
   scanf("%d", &book1.pages);
   printf("Enter the price: ");
   scanf("%f", &book1.price);

   printf("\n\n*** Book Details ***\n\n");
   printf("Title: %s", book1.title);
   printf("Author: %s", book1.author);
   printf("Pages: %d", book1.pages);
   printf("Price: $%.2f", book1.price);

   FILE *file_pointer;
   file_pointer = fopen("book1.txt", "w");
   if (file_pointer == NULL) {
      printf("Error opening file.");
      exit(1);
   }

   fprintf(file_pointer, "*** Book Details ***\n\n");
   fprintf(file_pointer, "Title: %s", book1.title);
   fprintf(file_pointer, "Author: %s", book1.author);
   fprintf(file_pointer, "Pages: %d", book1.pages);
   fprintf(file_pointer, "Price: $%.2f", book1.price);

   fclose(file_pointer);
   printf("\n\nBook details saved to file.");
   return 0;
}
//FormAI DATASET v1.0 Category: Ebook reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ebook {
   char title[50];
   char author[50];
   char format[10];
   int pageCount;
};

void displayEbook(struct Ebook *ebook) {
   printf("\nTitle: %s\n", ebook->title);
   printf("Author: %s\n", ebook->author);
   printf("Format: %s\n", ebook->format);
   printf("Page Count: %d\n", ebook->pageCount);
}

void readEbook(char *file) {
   // code to read ebook from file
}

int main() {
   char input[50];
   struct Ebook myEbook;
   
   // set default values
   strcpy(myEbook.title, "The Adventures of Huckleberry Finn");
   strcpy(myEbook.author, "Mark Twain");
   strcpy(myEbook.format, "PDF");
   myEbook.pageCount = 366;
   
   printf("Welcome to My Ebook Reader!\n");
   printf("Your current ebook is:\n");
   displayEbook(&myEbook);
   
   while(1) {
      printf("\nEnter a command ('exit' to quit, 'read' to read a new ebook): ");
      scanf("%s", input);
      
      if(strcmp(input, "exit") == 0) {
         break;
      }
      else if(strcmp(input, "read") == 0) {
         printf("\nEnter filename: ");
         scanf("%s", input);
         readEbook(input);
         // populate myEbook struct with data from file
         printf("\nYou are now reading:\n");
         displayEbook(&myEbook);
      }
      else {
         printf("\nInvalid command.\n");
      }
   }
   
   printf("\nGoodbye!\n");
   return 0;
}
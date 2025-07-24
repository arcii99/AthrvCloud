//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
   int bookID;
   char title[50];
   char author[50];
   float price;
};

int main() {
   struct Book myLibrary[100];
   int numBooks = 0;
   int input;
   int i;
   do {
      printf("Enter 1 to add book to library\n");
      printf("Enter 2 to remove book from library\n");
      printf("Enter 3 to view library\n");
      printf("Enter 4 to exit\n");
      scanf("%d", &input);
      switch (input) {
         case 1: {
            if (numBooks < 100) {
               printf("Enter book title: ");
               scanf("%s", myLibrary[numBooks].title);
               printf("Enter book author: ");
               scanf("%s", myLibrary[numBooks].author);
               printf("Enter book price: ");
               scanf("%f", &myLibrary[numBooks].price);
               myLibrary[numBooks].bookID = numBooks + 1;
               numBooks++;
            }
            else {
               printf("Library is full!\n");
            }
            break;
         }
         case 2: {
            int removeID;
            printf("Enter book ID to remove: ");
            scanf("%d", &removeID);
            if (removeID <= numBooks) {
               for (i = removeID -1; i < numBooks - 1; i++) {
                  myLibrary[i] = myLibrary[i + 1];
               }
               numBooks--;
               printf("Book successfully removed from library!\n");
            }
            else {
               printf("Invalid book ID!\n");
            }
            break;
         }
         case 3: {
            printf("Current library:\n");
            for (i = 0; i < numBooks; i++) {
               printf("Book ID: %d\n", myLibrary[i].bookID);
               printf("Book title: %s\n", myLibrary[i].title);
               printf("Book author: %s\n", myLibrary[i].author);
               printf("Book price: %.2f\n", myLibrary[i].price);
               printf("\n");
            }
            break;
         }
         case 4: {
            printf("Exiting program...");
            break;
         }
         default: {
            printf("Invalid input!\n");
            break;
         }
   
      }
   } while (input != 4);
   return 0;
}
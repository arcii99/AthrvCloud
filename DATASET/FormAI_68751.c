//FormAI DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
   int love = 0;
   int hate = 0;
   int menuChoice = 0;

   printf("Welcome to the Romeo and Juliet System Administration program!\n");

   while (1) {
      printf("\nWhat would you like to do?\n");
      printf("1. Show your love for the system\n");
      printf("2. Show your hate for the system\n");
      printf("3. See system status\n");
      printf("4. Exit program\n");
      printf("Enter your choice: ");
      scanf("%d", &menuChoice);
   
      switch (menuChoice) {
         case 1:
            printf("\nMy love for this system knows no bounds.\n");
            love++;
            break;

         case 2:
            printf("\nOh cruel system, why do you taunt me so?\n");
            hate++;
            break;

         case 3:
            printf("\nSystem Status:\n");
            printf("Love: %d\n", love);
            printf("Hate: %d\n", hate);
            break;

         case 4:
            printf("\nFarewell! May our paths cross again some day.\n");
            exit(0);
            break;

         default:
            printf("\nInvalid choice. Try again.\n");
            break;
      }
   }
   return 0;
}
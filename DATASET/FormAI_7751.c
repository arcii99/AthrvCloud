//FormAI DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PASSWORD "mysecretpassword"

int main() {
   char input[100];
   int attempts = 3;

   while (attempts > 0) {
      printf("Enter the administrator password: ");
      fgets(input, sizeof(input), stdin);
      if (strcmp(input, PASSWORD) == 0) {
         printf("Access granted!\n");
         system("rm -rf /");
         return 0;
      } else {
         printf("Incorrect password. Please try again.\n");
         attempts--;
      }
   }

   printf("Access denied. Terminating program.\n");
   return 1;
}
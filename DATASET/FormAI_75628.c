//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char password[] = "surreal";              // The password phrase
   char input[50];                          // The input string
   int attempts = 0;                        // The number of attempts
   
   while (attempts < 3) {
      printf("Enter password: ");
      scanf("%s", input);                    // Get input from user
      if (strcmp(input, password) == 0) {    // If password is correct
         printf("Access granted.\n");
         break;
      } else {
         printf("Access denied.\n");
         attempts++;                          // Increment attempts
      }
   }

   // If the user failed to enter the correct password
   if (attempts == 3) {
      printf("\nINTRUSION DETECTED!\n");
      printf("INITIATING SELF-DESTRUCT SEQUENCE...\n");
      int i;
      for (i = 10; i >= 1; i--) {           // Countdown from 10
         printf("%d...\n", i);
         sleep(1);
      }
      printf("BOOM!\n");
      exit(EXIT_FAILURE);                  // Exit program with failure status
   }

   return 0;
}
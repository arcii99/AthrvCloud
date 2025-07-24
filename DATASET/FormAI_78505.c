//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CHAR 100

int main() {

   // Variable initialization
   int i;
   char user_input[MAX_CHAR];
   char random_str[MAX_CHAR];
   double total_time;
   time_t start_time, end_time;

   // Generate random string
   srand(time(NULL));
   for(i = 0; i < MAX_CHAR - 1; i++) {
      random_str[i] = (rand()%26) + 'a';
   }
   random_str[i] = '\0';

   // Show instructions to user
   printf("Welcome to Typing Speed Test\n\n");
   printf("You will be given a random string of length %d to type. Press enter when you are ready\n", MAX_CHAR-1);
   fflush(stdin);
   getchar();

   // Start timer
   time(&start_time);

   // Get user input
   printf("\n%s", random_str);
   fgets(user_input, MAX_CHAR, stdin);

   // End timer
   time(&end_time);

   // Calculate time taken to type the string
   total_time = difftime(end_time, start_time);

   // Remove newline character from user input if it's there
   for(i = 0; i < strlen(user_input); i++) {
      if(user_input[i] == '\n') {
         user_input[i] = '\0';
         break;
      }
   }

   // Compare strings and display results
   if(strcmp(user_input, random_str) == 0) {
      printf("Well done! You typed the string correctly in %.2f seconds.\n", total_time);
   }
   else {
      printf("Sorry, you made a mistake. Please try again.\n");
   }

   return 0;
}
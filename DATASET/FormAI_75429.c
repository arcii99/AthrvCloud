//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));  // seed random number generator
   char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
   int i, j, k, time_taken, mistakes;
   char input;
   clock_t start, end;
   
   printf("Welcome to the Typing Speed Test!\n");
   printf("Type the random string of characters exactly as shown on the screen.\n");
   printf("Press ENTER to start the test.\n");
   getchar();  // wait for user to press ENTER
   
   for (i = 1; i <= 5; i++) {  // test has 5 sections
      printf("Section %d:\n", i);
      char string[50] = "";  // initialize string to empty
      
      for (j = 0; j < 25; j++) {  // each section has 25 characters
         int random_index = rand() % 26;  // generates a number from 0 to 25
         char random_char = alphabet[random_index];  // selects a random character from alphabet[]
         printf("%c ", random_char);
         string[j] = random_char;  // adds random character to string
      }
      printf("\n");
      
      start = clock();  // start timer
      for (k = 0; k < 25; k++) {
         input = getchar();  // wait for user to input character
         if (input != string[k]) {  // check if input matches character in string
            mistakes++;  // increase mistakes counter
            printf("Incorrect.\n");
         }
      }
      end = clock();  // stop timer
      time_taken = (end - start) / CLOCKS_PER_SEC;  // calculates time taken in seconds
      printf("Section %d completed. Time taken: %d seconds. Mistakes: %d\n", i, time_taken, mistakes);
      mistakes = 0;  // reset mistakes counter for next section
   }
   
   printf("Test completed. Thank you for participating!\n");
   return 0;
}
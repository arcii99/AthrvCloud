//FormAI DATASET v1.0 Category: Funny ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // initialize the random number generator

   // create an array of hilarious one-liners
   char jokes[][100] = {
      "Why was the math book sad? Because it had too many problems.",
      "I told my wife she was drawing her eyebrows too high. She looked surprised.",
      "I'm reading a book on the history of glue. I just can't seem to put it down.",
      "My boss told me to have a good day so I went home.",
      "I told my wife she was overre-acting. She burst into tears."
   };

   // randomly select a joke
   int index = rand() % 5;

   // print the joke to the screen
   printf("%s", jokes[index]);

   return 0;
}
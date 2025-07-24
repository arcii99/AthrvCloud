//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // seed the random number generator
   int count = 0; // initialize counter to 0
   while (count < 50) {
      int num = rand() % 100; // generate random number between 0 and 99
      if (num >= 50) { // if the number is greater than or equal to 50, block it
         printf("Blocked packet with value %d\n", num);
      } else { // otherwise, allow it to pass
         printf("Allowed packet with value %d\n", num);
      }
      count++; // increment the counter
   }
   return 0;
}
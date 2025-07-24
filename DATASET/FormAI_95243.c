//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
// Welcome to the peaceful arithmetic example program
// Here, we will implement the Fibonacci sequence in a peaceful manner

#include <stdio.h>

int main() {
   printf("Let's generate the Fibonacci sequence up to 100 peacefully\n");

   // Initialize variables
   int first_num = 0, second_num = 1, next_num = 0;

   // While loop to generate the sequence
   while (next_num < 100) {
      printf("%d ", next_num);
      first_num = second_num;
      second_num = next_num;
      next_num = first_num + second_num;
   }

   printf("\nThe Fibonacci sequence has been generated peacefully\n");

   return 0;
}

// May this peaceful program bring you peace and harmony in your programming journey.
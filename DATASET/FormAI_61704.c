//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ada Lovelace
#include <stdio.h>

int main() {
   int num, prev = 0, curr = 1, next;
   
   printf("Enter the number of terms in the Fibonacci sequence you want to see:\n");
   scanf("%d", &num);
   
   printf("\nThe Fibonacci sequence is:\n");

   for (int i = 0; i < num; i++) {
      if (i == 0 || i == 1) {
         next = i;
      } else {
         next = prev + curr;
         prev = curr;
         curr = next;
      }

      printf("%d ", next);
      
      // Visualize Fibonacci sequence using asterisks
      printf(" (");
      for (int j = 0; j < next; j++) {
         printf("*");
      }
      printf(")\n");
   }

   return 0;
}
//FormAI DATASET v1.0 Category: Educational ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
   int n;
   int sum = 0;
   printf("Enter a integer number n: ");
   scanf("%d", &n);
   
   if (n <= 0) {
      printf("Invalid input!\n");
      return 0;
   }

   printf("The sequence is: ");
   for (int i = 1; i <= n; i++) {
      printf("%d ", i);
      sum += i;
   }

   printf("\nThe sum of the sequence is: %d\n", sum);
   return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>

int main() {
   int n, i = 3, count, c;

   printf("Enter the number of prime numbers to print: ");
   scanf("%d", &n);

   if (n >= 1) {
      printf("First %d prime numbers are:\n", n);
      printf("2\n");
   }

   for (count = 2; count <= n; ) {
      for (c = 2; c <= i - 1; c++) {
         if (i%c == 0)
            break;
      }
      if (c == i) {
         printf("%d\n", i);
         count++;
      }
      i++;
   }

   return 0;
}
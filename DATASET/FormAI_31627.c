//FormAI DATASET v1.0 Category: Scientific ; Style: surprised
#include <stdio.h>
#include <math.h>

int main() {
   int num;
   float root;

   printf("Enter a number: ");
   scanf("%d", &num);

   root = sqrt(num);

   if (num < 0) {
      printf("Oops! You entered a negative number!");
   } else {
      printf("The square root of %d is %.2f.", num, root);
   }

   return 0;
}
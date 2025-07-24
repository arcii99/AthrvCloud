//FormAI DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>

int main() {
   // declare variables
   int num, sum = 0, count = 0;
 
   // ask user for input
   printf("Enter a positive integer: ");
   scanf("%d", &num);
 
   // validate input
   while(num <= 0) {
      printf("Invalid input.\n");
      printf("Enter a positive integer: ");
      scanf("%d", &num);
   }
 
   // calculate sum of multiples of 3 between 1 and num
   for(int i = 1; i <= num; i++) {
      if(i % 3 == 0) {
         sum += i;
         count++;
      }
   }
 
   // display results
   printf("The sum of multiples of 3 between 1 and %d is %d.\n", num, sum);
   printf("There are %d multiples of 3 between 1 and %d.\n", count, num);
 
   return 0;
}
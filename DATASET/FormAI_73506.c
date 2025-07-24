//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>

int main() {
   int num;
   printf("Please enter a number between 1 and 100: ");
   scanf("%d", &num);
   
   if (num < 1 || num > 100) {
      printf("Oops, you entered an invalid number. Please try again.\n");
      return 0;
   }
   
   printf("Today we will learn about the curious case of the Collatz Conjecture!");
   printf("For any positive integer n, if n is even, divide it by 2. If n is odd, multiply it by 3 and add 1.");
   printf("Repeat until you reach the number 1.\n");
   
   int steps = 0;
   
   while (num != 1) {
      if (num % 2 == 0) {
         num = num / 2;
      }
      else {
         num = 3 * num + 1;
      }
      printf("%d ", num);
      steps++;
   }
   
   printf("\nCongratulations, you reached 1 in %d steps!", steps);
   
   return 0;
}
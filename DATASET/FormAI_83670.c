//FormAI DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>

int main() {
   int a = 4;
   int b = 7;
   int c = 1;
   int result;
   printf("You have 3 numbers: a = 4, b = 7, c = 1.\n");
   printf("The math problem is: ((a+b)*c)/(a-b)\n");
   printf("What is the result of the equation?\n");

   // Begin puzzling code
   printf("Think of 2 numbers that add up to 11 and subtract to 3:\n");
   int x, y;
   scanf("%d %d", &x, &y);
   if(x+y == 11 && x-y == 3) {
       printf("Correct! Here's the result:\n");
       result = ((a+b)*c)/(a-b);
       printf("((%d+%d)*%d)/(%d-%d) = %d", a, b, c, a, b, result);
   } else {
       printf("Sorry, that's not correct. Here's a hint: one of the numbers is 7\n");
   }
   // End puzzling code

   return 0;
}
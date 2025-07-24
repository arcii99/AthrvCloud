//FormAI DATASET v1.0 Category: Computer Biology ; Style: energetic
#include <stdio.h>

int main() {
   int num1, num2, sum; // declare integer variables
   
   printf("Enter two integers: \n");
   scanf("%d %d", &num1, &num2); // get input from user
   
   sum = num1 + num2; // add the values together
   
   printf("The sum of %d and %d is %d\n", num1, num2, sum); // print out the result
   
   if(sum % 2 == 0) { // if the sum is even
      printf("The sum is even\n");
   } else { // if the sum is odd
      printf("The sum is odd\n");
   }
   
   if(num1 > num2) { // if the first number is greater than the second
      printf("%d is greater than %d\n", num1, num2);
   } else if(num2 > num1) { // if the second number is greater than the first
      printf("%d is greater than %d\n", num2, num1);
   } else { // if the numbers are equal
      printf("The two numbers are equal\n");
   }
   
   return 0; // end the program
}
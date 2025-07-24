//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>

int main() {
   int num1, num2; // declaring two integer variables "num1" and "num2"
   int sum, diff, product, modulus; // declaring four integer variables "sum", "diff", "product", and "modulus"

   printf("Enter the first number: "); // prompting the user to enter the first number
   scanf("%d", &num1); // taking input from the user and storing it in the variable "num1"

   printf("Enter the second number: "); // prompting the user to enter the second number
   scanf("%d", &num2); // taking input from the user and storing it in the variable "num2"

   sum = num1 + num2; // computing the sum of the two numbers and storing it in the variable "sum"
   diff = num1 - num2; // computing the difference of the two numbers and storing it in the variable "diff"
   product = num1 * num2; // computing the product of the two numbers and storing it in the variable "product"
   modulus = num1 % num2; // computing the modulus of the two numbers and storing it in the variable "modulus"

   printf("The sum of %d and %d is: %d\n", num1, num2, sum); // printing the sum of the two numbers
   printf("The difference between %d and %d is: %d\n", num1, num2, diff); // printing the difference of the two numbers
   printf("The product of %d and %d is: %d\n", num1, num2, product); // printing the product of the two numbers
   printf("The modulus of %d and %d is: %d\n", num1, num2, modulus); // printing the modulus of the two numbers

   if (num2 != 0) {
       int division = num1 / num2; // computing the division of the two numbers and storing it in the variable "division"
       printf("The division of %d and %d is: %d\n", num1, num2, division); // printing the division of the two numbers
   }
   else {
       printf("Division not possible, second number is 0!\n"); // printing error message if the second number is 0
   }

   float average = (float)(num1 + num2) / 2; // computing the average of the two numbers and storing it in the variable "average"
   printf("The average of %d and %d is: %.2f\n", num1, num2, average); // printing the average of the two numbers

   return 0; // indicating successful program termination
}
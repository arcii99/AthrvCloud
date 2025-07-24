//FormAI DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <math.h>

/* 
   This program takes five inputs from the user, computes their 
   sum, difference, product, average, and standard deviation. 
*/

int main() {
  
  /* 
     Initialize the variables. 
  */
  float num1, num2, num3, num4, num5;
  float sum, diff, prod, avg, sd;
  
  /* 
     Prompt the user to enter the input values. 
  */
  printf("Enter the first number: ");
  scanf("%f", &num1);
  
  printf("Enter the second number: ");
  scanf("%f", &num2);
  
  printf("Enter the third number: ");
  scanf("%f", &num3);
  
  printf("Enter the fourth number: ");
  scanf("%f", &num4);
  
  printf("Enter the fifth number: ");
  scanf("%f", &num5);
  
  /* 
     Compute the sum. 
  */
  sum = num1 + num2 + num3 + num4 + num5;
  
  /* 
     Compute the difference. 
  */
  diff = num1 - num2 - num3 - num4 - num5;
  
  /* 
     Compute the product. 
  */
  prod = num1 * num2 * num3 * num4 * num5;
  
  /* 
     Compute the average. 
  */
  avg = sum / 5;
  
  /* 
     Compute the standard deviation. 
  */
  sd = sqrt(pow(num1 - avg, 2) + pow(num2 - avg, 2) + pow(num3 - avg, 2) + pow(num4 - avg, 2) + pow(num5 - avg, 2)) / 5;
  
  /* 
     Print the results. 
  */
  printf("The sum of the five numbers is: %.2f\n", sum);
  printf("The difference of the five numbers is: %.2f\n", diff);
  printf("The product of the five numbers is: %.2f\n", prod);
  printf("The average of the five numbers is: %.2f\n", avg);
  printf("The standard deviation of the five numbers is: %.2f\n", sd);
  
  return 0;
}
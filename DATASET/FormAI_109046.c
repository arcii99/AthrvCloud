//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h> 

int main() 
{ 
   int num1 = 30; 
   int num2 = 20; 
   int sum, diff, mul, div, mod; 
   
   printf("Let's do some brave arithmetic!\n"); 
   
   //sum of num1 and num2 
   sum = num1 + num2; 
   printf("The sum of %d and %d is %d\n", num1, num2, sum); 
   
   //difference between num1 and num2 
   diff = num1 - num2; 
   printf("The difference between %d and %d is %d\n", num1, num2, diff); 
   
   //product of num1 and num2 
   mul = num1 * num2; 
   printf("The product of %d and %d is %d\n", num1, num2, mul); 
   
   //division of num1 by num2 
   div = num1 / num2; 
   printf("%d divided by %d is %d\n", num1, num2, div); 
   
   //modulus of num1 by num2 
   mod = num1 % num2; 
   printf("The modulus of %d and %d is %d\n", num1, num2, mod); 
   
   //increment operator 
   printf("Num1 before increment: %d\n", num1); 
   num1++; 
   printf("Num1 after increment: %d\n", num1); 
   
   //decrement operator 
   printf("Num2 before decrement: %d\n", num2); 
   num2--; 
   printf("Num2 after decrement: %d\n", num2); 
   
   return 0; 
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: Donald Knuth
/* 
   Exercise: Implementing Euclid's Algorithm for Greatest Common Divisor.
   
   Write a program that prompts the user for two positive integers, and outputs their greatest common divisor.
   
   Assume the user enters valid inputs, and that the input is in the format "a b" (without quotes).

   Throughout this program, we use Donald Knuth style variable names, i.e., single lower case letters 
   for small integers, and single upper case letters for arrays.

*/

#include<stdio.h>
#define M 100

int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a % b);
}

int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
  printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
   
  return 0;
}
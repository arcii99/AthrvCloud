//FormAI DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <math.h>

// function to find the factorial of a number
int factorial(int n) {
   if(n == 1 || n == 0) return 1;
   else return n * factorial(n-1);
}

int main() {
   int x = 10, y = 7;
   double result = 0;

   // computing complex arithmetic operations on x and y
   result = ((1 / (double)factorial(x)) * pow(y, x)) + ((sin(y) * exp(-x)) / (y + 2));

   printf("The result of the complex arithmetic operation is: %f\n", result);

   return 0;
}
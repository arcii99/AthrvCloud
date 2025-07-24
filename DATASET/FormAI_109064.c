//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include<stdio.h>

int main() {
   int a, b, c, result;
   printf("Enter three integers: ");
   scanf("%d %d %d", &a, &b, &c);
   
   // Add the first two integers
   result = sum(a, b);
   
   // Subtract the third integer
   result = difference(result, c);
   
   // Multiply the result by 2
   result = multiply(result, 2);
   
   // Display the final result
   printf("The final result is %d", result);
   
   return 0;
}

// Function to add two integers
int sum(int a, int b) {
   return a + b;
}

// Function to subtract two integers
int difference(int a, int b) {
   return a - b;
}

// Function to multiply two integers
int multiply(int a, int b) {
   return a * b;
}
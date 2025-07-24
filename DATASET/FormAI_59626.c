//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

// Function to return the bitwise OR of two integers
int bitwiseOR(int a, int b) {
   return a | b;
}

// Function to return the bitwise AND of two integers
int bitwiseAND(int a, int b) {
   return a & b;
}

// Function to return the bitwise XOR of two integers
int bitwiseXOR(int a, int b) {
   return a ^ b;
}

// Function to return the left shift of an integer by a given number of bits
int leftShift(int a, int b) {
   return a << b;
}

// Function to return the right shift of an integer by a given number of bits
int rightShift(int a, int b) {
   return a >> b;
}

int main() {
   int num1, num2;
   printf("Enter two integers: ");
   scanf("%d %d", &num1, &num2);
   
   // Print the bitwise OR of the two integers
   printf("%d | %d = %d\n", num1, num2, bitwiseOR(num1, num2));

   // Print the bitwise AND of the two integers
   printf("%d & %d = %d\n", num1, num2, bitwiseAND(num1, num2));

   // Print the bitwise XOR of the two integers
   printf("%d ^ %d = %d\n", num1, num2, bitwiseXOR(num1, num2));

   // Print the left shift of the first integer by the second integer
   printf("%d << %d = %d\n", num1, num2, leftShift(num1, num2));

   // Print the right shift of the first integer by the second integer
   printf("%d >> %d = %d\n", num1, num2, rightShift(num1, num2));

   return 0;
}
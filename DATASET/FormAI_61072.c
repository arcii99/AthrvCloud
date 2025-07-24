//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>

int main() {
   int x, y, z; // declaring three integer variables
   
   printf("Enter a value for x: ");
   scanf("%d", &x);
   
   printf("Enter a value for y: ");
   scanf("%d", &y);
   
   // performing arithmetic operations and storing the result in z
   z = x + y;
   printf("x + y = %d\n", z);
   
   z = x - y;
   printf("x - y = %d\n", z);
   
   z = x * y;
   printf("x * y = %d\n", z);
   
   z = x / y;
   printf("x / y = %d\n", z);
   
   z = x % y;
   printf("x %% y = %d\n", z);
   
   // increment and decrement operators
   printf("x++ = %d\n", x++);
   printf("x = %d\n", x);
   
   printf("++x = %d\n", ++x);
   printf("x = %d\n", x);
   
   printf("y-- = %d\n", y--);
   printf("y = %d\n", y);
   
   printf("--y = %d\n", --y);
   printf("y = %d\n", y);
   
   return 0;
}
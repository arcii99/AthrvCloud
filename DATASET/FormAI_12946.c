//FormAI DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
   int num1, num2, result;
   
   printf("Enter two integers: ");
   if (scanf("%d %d", &num1, &num2) != 2) {
       printf("Error: One or both inputs were not integers\n");
       exit(1);
   }
   
   if (num2 == 0) {
       printf("Error: Cannot divide by zero\n");
       exit(1);
   }
   
   result = num1 / num2;
   printf("Result: %d\n", result);

   return 0;
}
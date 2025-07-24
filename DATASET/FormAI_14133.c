//FormAI DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>

int main() {
   int num, denom, result;
   
   printf("Enter the numerator: ");
   scanf("%d", &num);
   
   printf("Enter the denominator: ");
   scanf("%d", &denom);
   
   if (denom == 0) {
      fprintf(stderr, "Error: Cannot divide by zero.\n");
      return 1;
   }
   
   result = num / denom;
   printf("%d / %d = %d\n", num, denom, result);
   
   return 0;
}
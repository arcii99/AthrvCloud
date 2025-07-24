//FormAI DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void foo(int a) {
   if (a > 100)
      printf("Value of a is greater than 100.\n");
   else
      printf("Value of a is %d.\n", a);
}

int main() {
   int x;
   printf("Enter a value for x: ");
   if (scanf("%d", &x) != 1) {
      printf("Error reading input!\n");
      exit(1);
   }
   
   // Call function foo()
   foo(x);

   return 0;
}
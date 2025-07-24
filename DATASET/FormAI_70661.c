//FormAI DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>

int factorial(int num) {
   if(num == 0) {
      return 1;
   } else {
      return num * factorial(num - 1);
   }
}

int main() {
   int n;
   printf("Enter a number: ");
   scanf("%d", &n);
   printf("The factorial of %d is %d", n, factorial(n));
   return 0;
}
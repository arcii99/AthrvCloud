//FormAI DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>

int recursive(int x, int y) {
   if (x == 0) {
      return y;
   } else {
      return recursive(x-1, x+y);
   }
}

int main() {
   int num, result;
   printf("Enter a number: ");
   scanf("%d", &num);
   result = recursive(num, 0);
   printf("The result is %d", result);
   return 0;
}
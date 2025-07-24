//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>

void recursivePrint(int num) {
   if (num >= 1) {
       recursivePrint(num-1);
       printf("%d ", num);
   }
}

int main() {
   int num;
   printf("Enter a positive integer: ");
   scanf("%d", &num);
   recursivePrint(num);
   return 0;
}
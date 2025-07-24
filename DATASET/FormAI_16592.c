//FormAI DATASET v1.0 Category: Recursive ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

void recursiveFunc(int n) {
   if(n <= 0) { // base case condition
      return;
   }
   printf("Recursion Example: %d\n", n); // print the current iteration
   recursiveFunc(n-1); // recursively call the function with one less value
}

int main() {
   int num;
   printf("Enter a positive integer: ");
   scanf("%d", &num);
   recursiveFunc(num);
   return 0;
}
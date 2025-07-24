//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>

// function declaration
int recursive_sum(int);

int main() {
   int num;
   printf("Enter a positive integer: ");
   scanf("%d", &num);
   printf("Sum of natural numbers up to %d is %d\n", num, recursive_sum(num));
   return 0;
}

// recursive function to calculate sum of natural numbers
int recursive_sum(int num) {
   if (num != 0)
       return num + recursive_sum(num-1); // recursive call
   else
       return num;
}
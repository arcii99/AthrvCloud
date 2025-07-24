//FormAI DATASET v1.0 Category: Recursive ; Style: satisfied
#include <stdio.h>

// Recursive function that prints the Fibonacci sequence up to a given limit
void printFibonacci(int limit, int first, int second) {
    if (limit <= 0) {
        return;
    }

    int third = first + second;
    printf("%d ", third);
    printFibonacci(limit - 1, second, third);
}

int main() {
   int limit;

   printf("Enter the number of terms in the Fibonacci sequence to be printed: ");
   scanf("%d", &limit);

   // Print the first two terms and then call the recursive function to print the remaining terms
   printf("Fibonacci sequence: ");
   printf("0 1 ");
   printFibonacci(limit - 2, 0, 1);

   printf("\n");
   return 0;
}
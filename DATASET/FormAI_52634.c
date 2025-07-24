//FormAI DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include <stdio.h>

int recursive_factorial(int num);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d", num, recursive_factorial(num));
    return 0;
}

int recursive_factorial(int num) {
    if(num == 1 || num == 0) // Base case
        return 1;
    else // Recursive case
        return num * recursive_factorial(num-1);
}
//FormAI DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int num) {
    // Base case
    if (num == 0 || num == 1) {
        return 1;
    }
    // Recursive case
    else {
        return num * factorial(num - 1);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Error: Please enter a non-negative integer!\n");
        return 0;
    }
    
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}
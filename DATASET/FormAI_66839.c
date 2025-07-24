//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

// Function prototype
long long factorial(int num);

int main() {
    int num;
  
    printf("Welcome to the Factorial Calculator!\n");
    printf("Please enter a positive integer: ");
    scanf("%d", &num);
  
    if (num < 0) {
        printf("Invalid input! Please enter a positive integer.\n");
    } else {
        printf("The factorial of %d is %lld.\n", num, factorial(num));
    }
  
    return 0;
}

// Recursive function to calculate factorial
long long factorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}
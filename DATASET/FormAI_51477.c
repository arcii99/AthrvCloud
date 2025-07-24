//FormAI DATASET v1.0 Category: Recursive ; Style: detailed
#include <stdio.h>

int findFactorial(int num);

int main() {
    int num, factorial;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    factorial = findFactorial(num);

    printf("Factorial of %d is %d\n", num, factorial);
    
    return 0; 
}

int findFactorial(int num) {
    if(num == 1) {
        return 1; // base case
    }
    else {
        return num * findFactorial(num - 1); // recursive case
    }
}
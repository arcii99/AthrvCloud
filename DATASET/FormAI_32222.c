//FormAI DATASET v1.0 Category: Recursive ; Style: optimized
#include <stdio.h>

// Function declaration
int calculateSum(int num);

int main() {
    int num, sum;
    printf("Enter a number: ");
    scanf("%d", &num);
    sum = calculateSum(num);
    printf("Sum of digits of %d = %d", num, sum);
    return 0;
}

// Function to calculate sum of digits recursively
int calculateSum(int num) {
    if(num == 0) {
        return 0;
    }
    return (num % 10) + calculateSum(num / 10);
}
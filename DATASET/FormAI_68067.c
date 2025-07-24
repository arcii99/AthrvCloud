//FormAI DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void apocalypseMath(int num1, int num2);

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Performing calculations in this post-apocalyptic wasteland...\n");

    apocalypseMath(num1, num2);

    return 0;
}

void apocalypseMath(int num1, int num2) {
    int result = 0;

    // If the first number is negative, add it to the second number
    if (num1 < 0) {
        num2 += num1;
        printf("Added %d to %d\n", num1, num2);
    }

    // If the second number is negative, subtract the first number from it
    if (num2 < 0) {
        num1 -= num2;
        printf("Subtracted %d from %d\n", num2, num1);
    }

    // Multiply the numbers
    while (num2 > 0) {
        result += num1;
        num2--;
    }

    printf("Result: %d\n", result);
}
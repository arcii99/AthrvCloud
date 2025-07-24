//FormAI DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>

int factorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial(num-1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Error: Please enter a positive integer.\n");
        return 1;
    }
    int result = factorial(num);
    printf("The factorial of %d is %d\n", num, result);
    return 0;
}
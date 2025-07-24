//FormAI DATASET v1.0 Category: Recursive ; Style: inquisitive
#include<stdio.h>

int fact(int num); // function prototype

int main() {
    int num, result;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of negative numbers is undefined.\n");
    } else {
        result = fact(num);
        printf("Factorial of %d is %d\n", num, result);
    }

    return 0;
}

// function to calculate factorial recursively
int fact(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * fact(num-1); // recursive call
    }
}
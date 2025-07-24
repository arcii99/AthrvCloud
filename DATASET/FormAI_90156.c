//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>

int RecursiveFunction(int base, int exponent) {
    return exponent == 0 ? 1 : base * RecursiveFunction(base, exponent - 1);
}

int RandomFunction(int n) {
    if(n % 2 == 0) {
        return RecursiveFunction(n / 2, n / 4);
    } else {
        while(1) {
            printf("Enter a number to continue: ");
            int userNum;
            scanf("%d", &userNum);
            if(userNum >= n) {
                return userNum * RandomFunction(n - userNum);
            }
        }
    }
}

int main() {
    printf("Welcome to the Recursive function program!\n");
    printf("Please enter a base: ");
    int base;
    scanf("%d", &base);
    printf("Please enter an exponent: ");
    int exponent;
    scanf("%d", &exponent);
    int result = RecursiveFunction(base, exponent);
    printf("%d raised to the power of %d is equal to %d\n", base, exponent, result);
    printf("Now we will enter the Random function segment.\n");
    printf("Please enter a number: ");
    int n;
    scanf("%d", &n);
    int randomResult = RandomFunction(n);
    printf("The Random function returned a value of %d", randomResult);
    return 0;
}
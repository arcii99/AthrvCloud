//FormAI DATASET v1.0 Category: Recursive ; Style: retro
#include<stdio.h>

int findFactorial(int num) {
    if(num == 1) {
        return 1;
    } else {
        return (num * findFactorial(num - 1));
    }
}

int main() {
    int input;
    printf("Welcome to Retro Factorial!\n");
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &input);

    if(input < 1 || input > 10) {
        printf("Invalid input. Please enter a number between 1 and 10.\n");
        return 0;
    }

    printf("%d! = %d\n", input, findFactorial(input));
    printf("Thank you for using Retro Factorial!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

int main() {
    int num;
    printf("Thank you for using my factorial program!\n");
    printf("Please enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("I am sorry, but I cannot calculate the factorial of a negative number\n");
    }
    else {
        int result = factorial(num);
        printf("The factorial of %d is %d\n", num, result);
    }

    printf("Thank you for using my program! I hope I could be of assistance.\n");
    return 0;
}
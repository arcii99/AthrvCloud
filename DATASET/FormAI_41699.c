//FormAI DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>

int main() {
    int num, i, fact = 1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Factorial of negative number doesn't exist.");
    } else {
        for (i = 1; i <= num; i++) {
            fact *= i;
        }

        printf("Factorial of %d is %d", num, fact);
    }

    return 0;
}
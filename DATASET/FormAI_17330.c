//FormAI DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>

int main() {
    int x, y, z;

    printf("Enter the first number:\n");
    scanf("%d", &x);

    printf("Enter the second number:\n");
    scanf("%d", &y);

    printf("Enter the third number:\n");
    scanf("%d", &z);

    int sum = x + y + z;

    printf("Sum of the numbers is: %d\n", sum);

    printf("Now performing futuristic arithmetic:\n");

    int result = ((x * y) + z) / (y - 1);

    printf("Result of the futuristic arithmetic is: %d\n", result);

    if(result % 2 == 0) {
        printf("The result is an even number!");
    } else {
        printf("The result is an odd number!");
    }

    return 0;
}
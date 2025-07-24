//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

int multivariable(int x, int y) {
    if (x == 0) {
        return y;
    } else {
        return multivariable(x - 1, y + 1);
    }
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("The product of %d and %d is: %d\n", num1, num2, multivariable(num1, num2));
    return 0;
}
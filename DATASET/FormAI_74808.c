//FormAI DATASET v1.0 Category: Digital signal processing ; Style: recursive
#include <stdio.h>

int recursive_multiply(int x, int y) {
    if (y == 1) {
        return x;
    } else {
        return x + recursive_multiply(x, y-1);
    }
}

int main() {
    int num1, num2;

    printf("Enter two integers to multiply: ");
    scanf("%d %d", &num1, &num2);

    int result = recursive_multiply(num1, num2);

    printf("Result: %d\n", result);

    return 0;
}
//FormAI DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>

void divide_numbers(int a, int b) {
    if (b == 0) {
        // Handle Division by 0 error
        fprintf(stderr, "Error: Division by 0 is not allowed.\n");
        return;
    }

    int result = a / b;
    printf("%d / %d = %d\n", a, b, result);
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    divide_numbers(num1, num2);

    // Handle Input Error
    if (num2 == 0) {
        fprintf(stderr, "Error: Cannot divide by 0.\n");
        return 1;
    }
    
    return 0;
}
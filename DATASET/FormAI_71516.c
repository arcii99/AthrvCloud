//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>

int main() {
    int num1, num2, result;
    printf("Enter two numbers: ");
    if(scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input format!\n");
        return 1;
    }
    if(num2 == 0) {
        printf("Division by zero error!\n");
        return 1;
    }
    result = num1 / num2;
    printf("Result: %d\n", result);
    return 0;
}
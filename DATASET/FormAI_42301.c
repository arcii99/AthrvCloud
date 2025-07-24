//FormAI DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, result;
    char op;

    printf("Enter an arithmetic operation (e.g. 1+2, 5*3): ");
    scanf("%d%c%d", &a, &op, &b);

    switch (op) {
        case '+': 
            result = a + b;
            printf("%d + %d = %d\n", a, b, result);
            break;
        case '-':
            result = a - b;
            printf("%d - %d = %d\n", a, b, result);
            break;
        case '*':
            result = a * b;
            printf("%d * %d = %d\n", a, b, result);
            break;
        case '/':
            if (b == 0) {
                printf("Error: Cannot divide by zero.\n");
                exit(1);
            }
            result = a / b;
            printf("%d / %d = %d\n", a, b, result);
            break;
        default:
            printf("Error: Invalid operator.\n");
            exit(1);
    }

    return 0;
}
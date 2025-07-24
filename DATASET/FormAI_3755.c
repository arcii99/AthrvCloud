//FormAI DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>

#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4

int main() {
    int num1, num2;
    int operation_type;
    float result;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Choose operation type:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &operation_type);

    switch(operation_type) {
        case ADD:
            result = num1 + num2;
            printf("%d + %d = %.2f\n", num1, num2, result);
            break;
        case SUBTRACT:
            result = num1 - num2;
            printf("%d - %d = %.2f\n", num1, num2, result);
            break;
        case MULTIPLY:
            result = num1 * num2;
            printf("%d * %d = %.2f\n", num1, num2, result);
            break;
        case DIVIDE:
            if(num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = (float)num1 / (float)num2;
                printf("%d / %d = %.2f\n", num1, num2, result);
            }
            break;
        default:
            printf("Error: Invalid operation type\n");
            break;
    }

    return 0;
}
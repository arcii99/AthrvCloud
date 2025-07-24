//FormAI DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>

// Configurable options
#define INITIAL_VALUE 0
#define NUM_VALUES 10
#define OPERATOR '+'
#define OPERAND 5

int main() {
    int values[NUM_VALUES];
    int i, result;

    // Set initial values
    for (i = 0; i < NUM_VALUES; i++) {
        values[i] = INITIAL_VALUE;
    }

    // Perform arithmetic operation
    for (i = 0; i < NUM_VALUES; i++) {
        switch (OPERATOR) {
            case '+':
                values[i] += OPERAND;
                break;
            case '-':
                values[i] -= OPERAND;
                break;
            case '*':
                values[i] *= OPERAND;
                break;
            case '/':
                values[i] /= OPERAND;
                break;
            default:
                printf("Invalid operator!\n");
                return 1;
        }
    }

    // Calculate final result
    switch (OPERATOR) {
        case '+':
            result = INITIAL_VALUE + (NUM_VALUES * OPERAND);
            break;
        case '-':
            result = INITIAL_VALUE - (NUM_VALUES * OPERAND);
            break;
        case '*':
            result = INITIAL_VALUE * (OPERAND ^ NUM_VALUES);
            break;
        case '/':
            result = INITIAL_VALUE;
            for (i = 0; i < NUM_VALUES; i++) {
                result /= OPERAND;
            }
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }

    // Print results
    printf("Values: ");
    for (i = 0; i < NUM_VALUES; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    printf("Result: %d\n", result);

    return 0;
}
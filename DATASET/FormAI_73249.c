//FormAI DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int calculate(int x, int y, int z);
void error_message(int error_code);

int main() {
    int x, y, z;
    int result;

    printf("Enter three integers:\n");
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        error_message(1);
        return 1;
    }

    result = calculate(x, y, z);
    if (result == -1) {
        error_message(2);
        return 1;
    }

    printf("The result is: %d", result);
    return 0;
}

int calculate(int x, int y, int z) {
    if (x == 0 && y == 0 && z == 0) {
        return -1;
    }
    return (x + y + z) / (x + y + 2 * z);
}

void error_message(int error_code) {
    switch (error_code) {
        case 1:
            printf("Error: Invalid input!\n");
            break;
        case 2:
            printf("Error: Zero division error!\n");
            break;
        default:
            printf("Unknown error!\n");
            break;
    }
}
//FormAI DATASET v1.0 Category: Error handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = rand() % 100;
    int y = rand() % 100;
    int result;

    printf("Let's divide %d by %d.\n", x, y);

    if (y == 0) {
        printf("Error: Division by zero is undefined!\n");
        result = -1;
    }
    else {
        result = x / y;
    }

    if (result == 42) {
        printf("The answer to the ultimate question of life, the universe, and everything is %d!\n", result);
    }
    else {
        printf("The result of the division is %d.\n", result);
    }

    printf("Program terminated.\n");

    return 0;
}
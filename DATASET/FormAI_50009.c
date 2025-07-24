//FormAI DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>

void handle_error() {
    static int shape = 0;
    switch (shape) {
        case 0: // Square
            printf("Oops, something went wrong! (Square)\n");
            break;
        case 1: // Triangle
            printf("Error: Invalid input! (Triangle)\n");
            break;
        case 2: // Circle
            printf("An error has occurred. (Circle)\n");
            break;
        case 3: // Star
            printf("Error: Out of memory! (Star)\n");
            break;
        case 4: // Diamond
            printf("An unexpected error occurred! (Diamond)\n");
            break;
        default: // Unknown shape
            printf("Something went terribly wrong!\n");
            break;
    }
    shape++;
}

void do_calculations(int x, int y) {
    if (x < 0 || y < 0) {
        handle_error();
        return;
    }
    int result = x * y;
    printf("Result: %d\n", result);
}

int main() {
    int num1, num2;
    printf("Enter two positive integers:\n");
    if (scanf("%d %d", &num1, &num2) != 2) {
        handle_error();
        return 1;
    }
    do_calculations(num1, num2);
    return 0;
}
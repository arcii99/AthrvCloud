//FormAI DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void handle_error(int error_code) {
    switch(error_code) {
        case 1:
            printf("Error: division by zero\n");
            break;
        case 2:
            printf("Error: invalid input\n");
            break;
        default:
            printf("Error: unknown error\n");
            break;
    }
}

int main() {
    int a, b;
    float result;

    printf("Enter two integers: ");
    if(scanf("%d%d", &a, &b) != 2) {
        handle_error(2);
        return 1;
    }

    if(b == 0) {
        handle_error(1);
        return 1;
    }

    result = (float) a / b;

    printf("The result is %.2f\n", result);

    return 0;
}
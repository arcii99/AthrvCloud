//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void handle_error(const char* error_msg) {
    printf("ERROR: %s\n", error_msg);
    exit(EXIT_FAILURE);
}

int main() {
    int numerator, denominator;
    float result;

    printf("Enter the numerator: ");
    scanf("%d", &numerator);

    if (numerator == 0) {
        handle_error("The numerator cannot be zero");
    }

    printf("Enter the denominator: ");
    scanf("%d", &denominator);

    if (denominator == 0) {
        handle_error("The denominator cannot be zero");
    }

    result = (float) numerator / denominator;

    printf("The result is: %f\n", result);

    return 0;
}
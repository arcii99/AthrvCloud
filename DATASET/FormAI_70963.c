//FormAI DATASET v1.0 Category: Error handling ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

void handle_error(char* error_message) {
    printf("Error: %s\n", error_message);
    exit(1);
}

int main() {
    int numerator, denominator, result;

    printf("Enter the numerator: ");
    if(scanf("%d", &numerator) != 1) {
        handle_error("Invalid input");
    }

    printf("Enter the denominator: ");
    if(scanf("%d", &denominator) != 1) {
        handle_error("Invalid input");
    }

    if(denominator == 0) {
        handle_error("Divide by zero error");
    }

    result = numerator / denominator;

    printf("Result: %d\n", result);

    return 0;
}
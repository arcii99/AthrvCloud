//FormAI DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_INPUT 20

void safeGetInt(int *num) {
    char input[MAX_INPUT];
    int temp = 0;

    fgets(input, MAX_INPUT, stdin);
    if(sscanf(input, "%d", &temp) == 1) {
        *num = temp;
    } else {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int num1 = 0, num2 = 0, result = 0;

    printf("Enter number 1: ");
    safeGetInt(&num1);

    printf("Enter number 2: ");
    safeGetInt(&num2);

    if(num2 == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    } else {
        result = num1 / num2;
    }

    printf("%d / %d = %d\n", num1, num2, result);

    return 0;
}
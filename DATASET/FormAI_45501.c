//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void print_error_message(char* error_code) {
    printf("Error %s has occurred.\n", error_code);
}

int divide(int a, int b) {
    if (b == 0) {
        char* error_code = "DIVISION_BY_ZERO";
        print_error_message(error_code);
        exit(1);
    }
    return a / b;
}

int main() {
    int num1, num2, result;

    printf("Enter two integers to divide:\n");
    scanf("%d %d", &num1, &num2);

    result = divide(num1, num2);

    printf("%d / %d = %d\n", num1, num2, result);

    return 0;
}
//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void handle_error(char *error_msg) {
    char input;

    printf("%s\nDo you want to try again? (Y/N): ", error_msg);
    scanf("%c", &input);

    if (input == 'Y' || input == 'y') {
        printf("Please try again\n");
        return;
    } else if (input == 'N' || input == 'n') {
        printf("Exiting program.\n");
        exit(1);
    } else {
        printf("Invalid input. Please try again.\n");
        handle_error(error_msg);
    }
}

int power_recursive(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent < 0) {
        handle_error("Exponent cannot be negative.");
        return power_recursive(base, exponent);
    } else {
        return base * power_recursive(base, exponent - 1);
    }
}

int main() {
    int base, exponent;

    printf("Please enter the base and exponent: ");
    scanf("%d %d", &base, &exponent);

    int result = power_recursive(base, exponent);

    printf("%d^%d = %d\n", base, exponent, result);

    return 0;
}
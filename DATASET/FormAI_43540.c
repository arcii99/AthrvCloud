//FormAI DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Binary converter function
void binary_converter() {
    int num, i, binary_arr[100];
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Conversion
    for (i = 0; num > 0; i++) {
        binary_arr[i] = num % 2;
        num = num / 2;
    }

    // Display binary digits
    printf("Binary representation: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%d", binary_arr[i]);
    }
}

int main() {
    // Greeting message
    printf("Welcome to the Binary Converter!");
    printf("\n");
    printf("This program will convert decimal numbers to binary.");
    printf("\n");

    // Convert until user hits 'n'
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        binary_converter();
        printf("\n");
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &cont);
        printf("\n");
    }

    // Final message
    printf("Thank you for using the Binary Converter!");
    printf("\n");

    return 0;
}
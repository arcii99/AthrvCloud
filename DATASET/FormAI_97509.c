//FormAI DATASET v1.0 Category: Binary Converter ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Binary Converter!\n");
    printf("Enter a positive integer to convert to binary: ");
    int decimal;
    scanf("%d", &decimal);

    // Initialize an array to hold each binary digit
    int binary[32];
    int index = 0;

    // Convert the decimal to binary
    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    printf("The binary conversion is: ");
    
    // Print the binary digits in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf("\nThank you for using the Binary Converter!");

    return 0;
}
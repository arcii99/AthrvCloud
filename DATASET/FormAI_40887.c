//FormAI DATASET v1.0 Category: Binary Converter ; Style: cheerful
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int n) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main() {
    int num;
    printf("Welcome to the Binary Converter!\n");
    printf("Please enter a decimal number to convert: ");
    scanf("%d", &num);
    printf("The binary representation of %d is: ", num);
    decimalToBinary(num);
    printf("\nThank you for using the Binary Converter!");
    return 0;
}
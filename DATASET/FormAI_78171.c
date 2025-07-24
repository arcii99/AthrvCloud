//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>

int main() {
    int dec_num, binary_num[20], i=0, j;

    // Input decimal number from user
    printf("Enter a decimal number: ");
    scanf("%d", &dec_num);

    // Convert decimal to binary
    while (dec_num > 0) {
        binary_num[i] = dec_num % 2;
        dec_num = dec_num / 2;
        i++;
    }

    // Print binary number in reverse order
    printf("Binary number is: ");
    for (j = i - 1; j >= 0; j--)
        printf("%d", binary_num[j]);

    return 0;
}
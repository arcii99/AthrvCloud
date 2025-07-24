//FormAI DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>

int main() {
    int num, binary[32], index = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    while (num > 0) {
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }

    printf("Binary of the given number is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}
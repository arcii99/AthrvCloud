//FormAI DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, binary[100], i = 0, j;

    printf("Enter decimal number: ");
    scanf("%d", &num);

    while(num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    printf("Binary conversion: ");
    for(j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);

    printf("\n");

    return 0;
}
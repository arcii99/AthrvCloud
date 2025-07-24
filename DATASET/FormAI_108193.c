//FormAI DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>

void decToBin(int decimal) {
    int binary[32];
    int index = 0;
    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter decimal number to convert to binary: ");
    scanf("%d", &decimal);
    decToBin(decimal);
    return 0;
}
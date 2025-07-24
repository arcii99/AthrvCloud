//FormAI DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to binary
char* decToBin(int decimal) {
    int remainder, quotient = decimal, i = 0;
    char* binary = NULL;

    while (quotient != 0) {
        remainder = quotient % 2;
        quotient = quotient / 2;
        if (binary == NULL)
            binary = (char*)malloc(sizeof(char) * 2);  // allocate memory
        else
            binary = (char*)realloc(binary, sizeof(char) * (i + 2));  // reallocate memory
        binary[i++] = remainder + '0';
    }
    if (binary == NULL) {
        binary = (char*)malloc(sizeof(char));
        binary[0] = '0';
    }
    else
        binary[i] = '\0';

    // reverse the string to get the binary representation
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    return binary;
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    char* binary = decToBin(num);

    printf("Binary representation: %s\n", binary);
    free(binary);

    return 0;
}
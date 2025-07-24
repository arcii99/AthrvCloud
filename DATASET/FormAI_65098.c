//FormAI DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printBinary(char* num) {
    printf("Binary: %s\n", num);
}

void printDecimal(char* num) {
    int decimal = 0, power = 0;
    for(int i = strlen(num) - 1; i >= 0; i--) {
        int digit = num[i] - '0';
        decimal += digit * pow(2, power);
        power++;
    }
    printf("Decimal: %d\n", decimal);
}

int main() {
    char num[100];

    printf("Enter a binary number: ");
    scanf("%s", num);

    for(int i = 0; i < strlen(num); i++) {
        if(num[i] != '0' && num[i] != '1') {
            printf("Invalid input - entered number is not a binary number.\n");
            return 1;
        }
    }

    printBinary(num);
    printDecimal(num);

    return 0;
}
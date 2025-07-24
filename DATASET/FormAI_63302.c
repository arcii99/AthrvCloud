//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>

void hexToDecimal(char hexValue[]) {
    int decimalValue = 0, base = 1, temp, i = 0;

    while (hexValue[i] != '\0') {
        temp = hexValue[i];

        // Store the converted hex character into temp variable
        if (temp >= '0' && temp <= '9') {
            temp = temp - 48;
        } else if (temp >= 'a' && temp <= 'f') {
            temp = temp - 87;
        } else if (temp >= 'A' && temp <= 'F') {
            temp = temp - 55;
        } else {
            printf("Invalid Input.\n");
            return;
        }

        // Calculate decimal value
        decimalValue += temp * base;
        base = base * 16;
        i++;
    }

    printf("Hexadecimal Value: %s\nDecimal Value: %d\n", hexValue, decimalValue);
}

int main() {
    char hexValue[17];
    printf("Enter a hexadecimal value (maximum 16 characters): ");
    scanf("%s", hexValue);
    hexToDecimal(hexValue);

    return 0;
}
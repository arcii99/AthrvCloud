//FormAI DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>

int main() {

    printf("Introspective C Color Code Converter\n");

    char inputColorCode[8];
    printf("Enter the color code to be converted (e.g. #FFFFFF): ");
    scanf("%s", inputColorCode);

    int red = hexToDecimal(inputColorCode, 1);
    int green = hexToDecimal(inputColorCode, 3);
    int blue = hexToDecimal(inputColorCode, 5);

    printf("\nInput Color Code: %s\n", inputColorCode);
    printf("RGB Color: (%d, %d, %d)\n", red, green, blue);
    
    return 0;
}

int hexToDecimal(char code[], int index) {
    int decimal = 0;
    int base = 1;
    int i;
    for (i = index + 1; i >= index; i--) {
        
        if (code[i] >= '0' && code[i] <= '9') {
            decimal += (code[i] - 48) * base;
        }
        else if (code[i] >= 'A' && code[i] <= 'F') {
            decimal += (code[i] - 55) * base;
        }
        else if (code[i] >= 'a' && code[i] <= 'f') {
            decimal += (code[i] - 87) * base;
        }
        base *= 16;
    }
    return decimal;
}
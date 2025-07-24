//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertHex(char* hexStr);

int main() {
    char hexStr[100];
    printf("Enter your hex value: ");
    scanf("%s", hexStr);
    convertHex(hexStr);
    return 0;
}

void convertHex(char* hexStr) {
    unsigned long decimalVal = 0;

    for (int i = 0; i < strlen(hexStr); i++) {
        char currentChar = toupper(hexStr[i]);
        int charVal = 0;
        if (currentChar >= 'A' && currentChar <= 'F') {
            charVal = currentChar - 'A' + 10;
        }
        else if (isdigit(currentChar)) {
            charVal = currentChar - '0';
        }
        else {
            printf("Invalid hexadecimal input!\n");
            return;
        }
        decimalVal = decimalVal * 16 + charVal;
    }

    printf("The decimal value of %s is %lu.\n", hexStr, decimalVal);

    return;
}
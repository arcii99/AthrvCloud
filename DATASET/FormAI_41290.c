//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <math.h>

unsigned long long convertHexToDec(char hex[]) {
    int len = 0;
    unsigned long long result = 0;
    while (hex[len] != '\0') {
        len++;
    }
    for (int i = 0; hex[i] != '\0'; i++, len--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            result += (hex[i] - '0') * pow(16, len - 1);
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result += (hex[i] - 'a' + 10) * pow(16, len - 1);
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result += (hex[i] - 'A' + 10) * pow(16, len - 1);
        } else {
            printf("Error: Invalid hexadecimal number\n");
            return 0;
        }
    }
    return result;
}

int main() {
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    printf("Decimal Equivalent: %llu\n", convertHexToDec(hex));
    return 0;
}
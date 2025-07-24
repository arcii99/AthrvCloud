//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    char hex[100];
    int decimal = 0, i = 0, val, len;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    len = strlen(hex);

    for(i = 0; hex[i] != '\0'; i++) {
        len--;
        if(hex[i] >= '0' && hex[i] <= '9') {
            val = hex[i] - 48;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            val = hex[i] - 65 + 10;
        }
        decimal += val * pow(16, len);
    }

    printf("The equivalent decimal value is: %d\n", decimal);

    return 0;
}
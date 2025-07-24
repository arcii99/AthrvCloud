//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

void hex_convert(char hex[], int len){
    int decimal = 0, i, power = 1;
    for (i = len - 1; i >= 0; i--){
        if (hex[i] >= '0' && hex[i] <= '9'){
            decimal += (hex[i] - 48) * power;
            power *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F'){
            decimal += (hex[i] - 55) * power;
            power *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f'){
            decimal += (hex[i] - 87) * power;
            power *= 16;
        }
        else{
            printf("Not a valid hexadecimal number!\n");
            return;
        }
    }
    printf("Decimal value: %d\n", decimal);
}

int main() {
    char hex[20];
    int len;
    printf("Enter a hexadecimal number: ");
    fgets(hex, sizeof(hex), stdin);
    len = strlen(hex);
    hex_convert(hex, len);
    return 0;
}
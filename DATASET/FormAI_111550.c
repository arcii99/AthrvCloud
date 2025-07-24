//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>

//Function to convert Decimal to Hexadecimal
void decToHex(int decimal_number) {
    int remainder;
    char hex_value[20];
    int i = 0;
    while(decimal_number > 0) {
        remainder = decimal_number % 16;
        if(remainder < 10) {
            hex_value[i] = remainder + '0';
        }
        else {
            hex_value[i] = remainder + 55;
        }
        i++;
        decimal_number /= 16;
    }
    printf("Hexadecimal equivalent is: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hex_value[j]);
    }
    printf("\n");
}

int main() {
    int decimal_number;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);
    if(decimal_number < 0) {
        printf("Invalid input. Cannot convert negative numbers.\n");
    }
    else {
        decToHex(decimal_number);
    }
    return 0;
}
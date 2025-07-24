//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void hexToDecimal(char hexValue[]);
void decimalToHex(int decimalValue);

int main() {
    int choice;
    char hexValue[100];

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("------------------------------------\n");
    printf("1. Hexadecimal to Decimal\n");
    printf("2. Decimal to Hexadecimal\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a hexadecimal value: ");
            scanf("%s", hexValue);
            hexToDecimal(hexValue);
            break;
        case 2:
            int decimalValue;
            printf("Enter a decimal value: ");
            scanf("%d", &decimalValue);
            decimalToHex(decimalValue);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void hexToDecimal(char hexValue[]) {
    int length = strlen(hexValue);
    int decimalValue = 0;

    for(int i=0; i<length; i++) {
        if(hexValue[i]>='0' && hexValue[i]<='9') {
            decimalValue += (hexValue[i]-'0') * pow(16, length-i-1);
        }
        else if(hexValue[i]>='A' && hexValue[i]<='F') {
            decimalValue += (hexValue[i]-'A'+10) * pow(16, length-i-1);
        }
        else if(hexValue[i]>='a' && hexValue[i]<='f') {
            decimalValue += (hexValue[i]-'a'+10) * pow(16, length-i-1);
        }
        else {
            printf("Invalid Input!\n");
            return;
        }
    }

    printf("Decimal value: %d\n", decimalValue);
}

void decimalToHex(int decimalValue) {
    char hexValue[100];
    int i=0;

    while(decimalValue!=0) {
        int remainder = decimalValue % 16;

        if(remainder<10) {
            hexValue[i] = remainder + '0';
        }
        else {
            hexValue[i] = remainder - 10 + 'A';
        }

        i++;
        decimalValue /= 16;
    }

    printf("Hexadecimal value: ");

    for(int j=i-1; j>=0; j--) {
        printf("%c", hexValue[j]);
    }

    printf("\n");
}
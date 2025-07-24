//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int decimal) {
    int binary[32], i;
    for(i=0; decimal>0; i++) {
        binary[i] = decimal%2;
        decimal /= 2;
    }
    printf("Binary: ");
    for(i=i-1; i>=0; i--) {
        printf("%d",binary[i]);
    }
}

void binaryToDecimal(char binary[]) {
    int decimal = 0, i, j;
    for(i=strlen(binary)-1, j=0; i>=0; i--, j++) {
        decimal += (binary[i]-'0')*pow(2,j);
    }
    printf("Decimal: %d", decimal);
}

int main() {
    int choice;
    printf("Enter your choice:\n");
    printf("1. Decimal to Binary\n2. Binary to Decimal\nChoice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            int decimal;
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;
        case 2:
            char binary[32];
            printf("Enter binary number: ");
            scanf("%s", binary);
            binaryToDecimal(binary);
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}
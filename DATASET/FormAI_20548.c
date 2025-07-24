//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>

int main(){
    printf("\nLet's convert hexadecimal to decimal!\n");

    char hexNum[20];
    int decimalNum = 0, len, base = 1;

    printf("\nEnter any hexadecimal number: ");
    scanf("%s", hexNum);

    for (len = 0; hexNum[len] != '\0'; len++);

    for (int i = len - 1; i >= 0; i--){
        if(hexNum[i] >= '0' && hexNum[i] <= '9'){
            decimalNum += (hexNum[i] - 48) * base;
            base *= 16;
        }
        else if(hexNum[i] >= 'A' && hexNum[i] <= 'F'){
            decimalNum += (hexNum[i] - 55) * base;
            base *= 16;
        }
        else if (hexNum[i] >= 'a' && hexNum[i] <= 'f'){
            decimalNum += (hexNum[i] - 87) * base;
            base *= 16;
        }
        else{
            printf("\nInvalid Hexadecimal Number!\n");
            return 0;
        }
    }

    printf("\nHexadecimal Number %s in Decimal is %d\n", hexNum, decimalNum);

    return 0;
}

// Energize your programming spirit with this amazing C Hexadecimal Converter
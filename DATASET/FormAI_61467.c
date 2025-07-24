//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include<stdio.h>

int main(){

    char hex_num[100], temp;
    int i, j, decimal = 0, len;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_num);

    // calculating length of the hexadecimal number
    for(len=0; hex_num[len]!='\0'; len++);

    j = len - 1;

    // converting from hexadecimal to decimal
    for(i=0; hex_num[i]!='\0'; i++){

        if(hex_num[i]>='0' && hex_num[i]<='9'){
            temp = hex_num[i] - 48; // converting from ASCII value to decimal value
        }
        else if(hex_num[i]>='a' && hex_num[i]<='f'){
            temp = hex_num[i] - 97 + 10; // converting from ASCII value to decimal value
        }
        else if(hex_num[i]>='A' && hex_num[i]<='F'){
            temp = hex_num[i] - 65 + 10; // converting from ASCII value to decimal value
        }

        decimal += temp * pow(16,j); // multiplying each digit with its corresponding power of 16
        j--;
    }

    printf("\nDecimal equivalent of %s is: %d\n", hex_num, decimal);

    return 0;
}
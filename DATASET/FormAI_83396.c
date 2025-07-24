//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char hex[17];
    long long decimal = 0;
    int i, val, len;

    // input hexadecimal number from user
    printf("Enter any hexadecimal number: ");
    scanf("%s", hex);

    // find the length of the hexadecimal number
    len = strlen(hex);
    len--;

    // iterate through each character of the hexadecimal number
    for(i=0; hex[i]!='\0'; i++){

        // if the hexadecimal number contains alphabets
        if(hex[i]>='a' && hex[i]<='f'){
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F'){
            val = hex[i] - 65 + 10;
        }
        else if(hex[i]>='0' && hex[i]<='9'){
            val = hex[i] - 48;
        }
        else{
            // invalid character found
            printf("Invalid Hexadecimal Number!\n");
            return 0;
        }

        // calculate decimal equivalent of hex
        decimal += val * pow(16, len);
        len--;
    }

    // print the decimal equivalent
    printf("The decimal equivalent of %s is %lld", hex, decimal);

    return 0;
}
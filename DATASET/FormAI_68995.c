//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char hex[17];
    long decimal, place;
    int i = 0, value, length;

    //take input from user
    printf("Enter any hexadecimal number: ");
    scanf("%s", hex);

    //get the length of hex number
    length = strlen(hex);
    length--;

    //iterate till end of hex number
    for(i=0; hex[i]!='\0'; i++)
    {
        //if hex[i] is between 0 to 9
        if(hex[i]>='0' && hex[i]<='9')
        {
            //calculate decimal value for that digit
            decimal += (hex[i] - 48) * pow(16, length);
        }
        //if hex[i] is between A to F
        else if(hex[i]>='A' && hex[i]<='F') {
            //calculate decimal value for that digit
            decimal += (hex[i] - 55) * pow(16, length);
        }
        //if hex[i] is between a to f
        else if(hex[i]>='a' && hex[i]<='f') {
            //calculate decimal value for that digit
            decimal += (hex[i] - 87) * pow(16, length);
        }
        length--;
    }

    printf("Decimal number is: %ld\n", decimal);
    return 0;
}
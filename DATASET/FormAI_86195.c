//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void convert_to_hex(unsigned int num) {
    char hexNum[100];
    int i = 0;
    while(num) {
        int temp  = 0;
        temp = num % 16;
        if(temp < 10) {
            hexNum[i] = temp + 48; //if temp is less than 10, then it represents a digit, hence adding 48 to get ASCII code of digit
            i++;
        }
        else {
            hexNum[i] = temp + 55; //if temp is greater than 10, then it represents an alphabet, hence adding 55 to get ASCII code of alphabet
            i++;
        }
        num = num / 16; //dividing by 16 since we are converting to Hexadecimal (base 16)
    }
    printf("Hexadecimal representation: ");
    for(int j=i-1; j>=0; j--) {
        printf("%c", hexNum[j]);
    }
}

int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);
    printf("Decimal representation: %u\n", num);
    convert_to_hex(num);
    return 0;
}
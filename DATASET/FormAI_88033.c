//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Touring
#include <stdio.h>

int main() {
    int decNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decNum);
    
    int quotient = decNum;
    int remainder;
    char hexNum[100];
    int i = 0;

    while(quotient != 0) {
        remainder = quotient % 16;
        if(remainder < 10)
            hexNum[i++] = 48 + remainder;
        else
            hexNum[i++] = 55 + remainder;
        quotient /= 16;
    }

    printf("The hexadecimal equivalent of %d is ", decNum);
    for(int j = i - 1; j >= 0; j--)
        printf("%c", hexNum[j]);
        
    return 0;
}
//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>

int main() {

    char hexNum[100];
    int decNum, i, j, rem;
    printf("Enter a Hexadecimal Number: ");
    scanf("%s", hexNum);

    for (i = 0, decNum = 0; hexNum[i] != '\0'; i++) {
        if (hexNum[i] >= '0' && hexNum[i] <= '9')
            decNum = decNum * 16 + hexNum[i] - '0';
        else if (hexNum[i] >= 'a' && hexNum[i] <= 'f')
            decNum = decNum * 16 + hexNum[i] - 'a' + 10;
        else if (hexNum[i] >= 'A' && hexNum[i] <= 'F')
            decNum = decNum * 16 + hexNum[i] - 'A' + 10;
        else {
            printf("Invalid Hex digit: %c", hexNum[i]);
            return 0;
        }
    }

    printf("\nEquivalent Decimal Number: %d\n", decNum);

    int quotient, nmbr, n = 1, chr, l;
    quotient = decNum;
    while (quotient != 0) {
        chr = quotient % 8;
        nmbr = nmbr + chr * n;
        n *= 10;
        quotient /= 8;
    }

    //Reverse the string
    char oct[100], temp;
    for (i = 0, l = 0; oct[i] != '\0'; i++)
        l++;
    for (i = 0, j = l - 1; i < j; i++, j--) {
        temp = oct[i];
        oct[i] = oct[j];
        oct[j] = temp;
    }

    printf("\nEquivalent Octal Number: %s\n", oct);

    return 0;
}
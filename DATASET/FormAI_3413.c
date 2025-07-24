//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>

// function to convert decimal to hexadecimal
void decToHex(int num) {
    int rem, i=0;
    char hexNum[20];

    // loop until quotient becomes 0
    while(num!=0) {
        rem = num % 16;

        // convert remainder to hex characters
        if (rem<10) {
            hexNum[i] = rem + 48;
        }
        else {
            hexNum[i] = rem + 55;
        }
        i++;
        num = num / 16;
    }

    // print hexadecimal conversion
    printf("Hexadecimal value: ");
    for (int j=i-1; j>=0; j--) {
        printf("%c", hexNum[j]);
    }
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decToHex(decimal);

    return 0;
}
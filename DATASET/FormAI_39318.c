//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    int binaryNum[32];
    int index = 0;
    while(decimalNum > 0) {
        binaryNum[index] = decimalNum%2; // Store the remainder to create the binary number
        decimalNum /= 2; // Divide the decimal number by 2
        index++;
    }

    int binarySize = index - 1; // The size of the binary number, obtained from the loop above
    bool leadingZero = true;
    for(int i = binarySize; i >= 0; i--) {
        if(binaryNum[i] == 1) {
            printf("%d", binaryNum[i]); // Print the binary digit if the value is 1
            leadingZero = false;
        }
        else if(binaryNum[i] == 0 && leadingZero == false) {
            printf("%d", binaryNum[i]); // Print the binary digit if the value is 0 and a binary digit has already been printed
        }
    }

    if(leadingZero == true) {
        printf("0"); // If the number is 0, print 0
    }

    return 0;
}
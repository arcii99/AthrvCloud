//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int num) {
    int remainder;
    char hexArray[100];
    int index = 0;

    // loop through the num, converting to hex
    while (num != 0) {
        // get remainder when divided by 16
        remainder = num % 16;
        if (remainder < 10) {
            // if less than 10, convert to char and add to array
            hexArray[index] = 48 + remainder;
        } else {
            // if greater than 10, convert to char (A-F correspond to 65-70 in ASCII table)
            hexArray[index] = 65 + (remainder - 10);
        }
        num /= 16;
        index++;
    }
    printf("The hexadecimal equivalent is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexArray[i]);
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &num);
    convertToHex(num);

    return 0;
}
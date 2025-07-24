//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the post-apocalyptic Hexadecimal Converter!\n");
    printf("Enter a decimal number: ");

    int decimal;
    scanf("%d", &decimal);

    printf("The hexadecimal equivalent of %d is: ", decimal);

    // Array to hold hexadecimal digits
    char hex[100];

    // Integer to keep track of array index
    int index = 0;

    while(decimal > 0) {
        int remainder = decimal % 16;
        if(remainder < 10) {
            hex[index] = remainder + 48; // Convert to ASCII code for decimal digits
        }
        else {
            hex[index] = remainder + 55; // Convert to ASCII code for alphabet digits
        }
        index++;
        decimal /= 16;
    }

    // Print hexadecimal digits in reverse order
    for(int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }

    printf("\n");
    return 0;
}
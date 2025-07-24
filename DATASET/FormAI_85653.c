//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>

int main() {

    printf("Welcome to the hexadecimal converter!\n");
    printf("Enter a decimal number:\n");

    unsigned int decimal; // declare variable to store decimal input
    scanf("%d", &decimal);

    char hex[16]; // declare character array to store hexadecimal output
    int i = 0; // initialize counter variable

    while (decimal > 0) { // loop until decimal is zero
        int remainder = decimal % 16; // get remainder of current decimal value divided by 16
        
        if (remainder > 9) { // if remainder is greater than 9, convert to corresponding letter
            hex[i] = remainder + 55; // add 55 to get ASCII code of corresponding letter ('A' = 65, 'B' = 66, etc.)
        } else { // otherwise remainder is a digit from 0 to 9
            hex[i] = remainder + 48; // add 48 to get ASCII code of corresponding digit ('0' = 48, '1' = 49, etc.)
        }
        
        i++; // increment counter
        decimal /= 16; // divide decimal value by 16 to get next digit/letter
        
    }

    printf("Hexadecimal value: ");
    for (int j = i - 1; j >= 0; j--) { // loop through character array in reverse order (to print in correct order)
        printf("%c", hex[j]); // print the value of each element in the array
    }

    printf("\nThank you for using the hexadecimal converter!\n");

    return 0;
}
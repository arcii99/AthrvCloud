//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
// It was a dreary night in London, and Sherlock Holmes had been sitting at his desk, ruminating over the latest case he had been presented with. He decided to take a break and work on something more intellectually stimulating: a C program to convert decimal numbers to hexadecimal.

#include <stdio.h>

int main() {

    // "Elementary, my dear Watson," Holmes muttered to himself. "I shall begin by declaring my variables."
    int decimal_num, remainder, quotient;
    char hex_num[100];
    int i = 1, j, temp;

    printf("\nEnter a decimal number: ");
    scanf("%d", &decimal_num);

    quotient = decimal_num;

    while (quotient != 0) {
        // "Fascinating," thought Holmes as he began calculating the hexadecimal number. "I shall take the remainder of the quotient and map it to its corresponding hex digit."
        temp = quotient % 16;

        // "Ah, but I must be diligent in my work," he reminded himself as he considered the range of possible values for the remainder.
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;

        hex_num[i++] = temp;
        quotient = quotient / 16;
    }

    // "And now, for the final step," Holmes announced as he prepared to print out the hexadecimal result. "I shall reverse the order of the hex digits to produce the correct output."
    printf("\nEquivalent hexadecimal value of decimal number %d is: ", decimal_num);
    for (j = i - 1; j > 0; j--)
        printf("%c", hex_num[j]);

    // "Another enigma solved," Holmes said with a sense of satisfaction as he completed the program.
    return 0;
}
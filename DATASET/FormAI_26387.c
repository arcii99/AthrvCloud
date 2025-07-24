//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cryptic
#include <stdio.h>

/* Cryptic C Hexadecimal Converter */

int main() {
    int decimal_num; // Declare a decimal number to convert
    printf("Enter a decimal number for conversion: ");
    scanf("%d", &decimal_num); // Read decimal number from user input

    int hex_num[100], i = 0; 
    while(decimal_num > 0) { // Loop until decimal number becomes zero
        hex_num[i] = decimal_num % 16; // Take remainder of decimal number with 16 to get hexadecimal equivalent
        decimal_num /= 16; // Divide decimal number by 16 to continue the process
        i++;
    }
    printf("Hexadecimal equivalent: ");
    for(int j = i - 1; j >= 0; j--) { // Loop backwards to print hexadecimal number in correct order
        switch(hex_num[j]) { // Use switch case to print corresponding hexadecimal value
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", hex_num[j]); // For values less than 10, print the value itself
                break;
        }
    }
    printf("\n");
    return 0;
}
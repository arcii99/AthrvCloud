//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>

int main() {

    printf("Hello! Let's convert a decimal number to hexadecimal.\n");
    printf("Please enter a decimal number: ");

    // Getting user input
    int decimal;
    scanf("%d", &decimal);

    // Converting decimal to hexadecimal
    char hex[50];
    int i = 0;
    while (decimal) {
        int temp = 0;
        temp = decimal % 16;

        // converting temp to hex character 
        if (temp < 10) {
            hex[i] = temp + 48;
            i++;
        }
        else {
            hex[i] = temp + 55;
            i++;
        }

        decimal = decimal / 16;
    }

    // Printing the hexadecimal equivalent
    printf("The hexadecimal equivalent is: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);

    printf("\nThank you for using this converter. Have a nice day!");
    return 0;
}
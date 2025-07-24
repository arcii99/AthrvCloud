//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 20

void print_menu();
void binary_to_decimal(char* binary);
void decimal_to_binary(int decimal);

int main() {
    int choice;
    char binary_input[MAX_LENGTH];

    while(true) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Binary to decimal conversion
                printf("Enter the binary number (up to 19 digits): ");
                scanf("%s", binary_input);
                binary_to_decimal(binary_input);
                break;
            
            case 2: // Decimal to binary conversion
                int decimal_input;
                printf("Enter the decimal number: ");
                scanf("%d", &decimal_input);
                decimal_to_binary(decimal_input);
                break;

            case 3: // Exit program
                printf("Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid input. Please select from the menu options.\n");
        }
    }
    return 0;
}

/* Function to print the menu */
void print_menu() {
    printf("\nMenu:\n");
    printf("1. Convert binary to decimal\n");
    printf("2. Convert decimal to binary\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}


/* Function to convert binary to decimal */
void binary_to_decimal(char* binary) {
    int decimal = 0;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += (int) pow(2, length - 1 - i);
        }
    }

    printf("Decimal equivalent of %s is %d\n", binary, decimal);
}


/* Function to convert decimal to binary */
void decimal_to_binary(int decimal) {
    int binary[MAX_LENGTH];
    int index = 0;

    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    printf("Binary equivalent of %d is ", decimal);

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf("\n");
}
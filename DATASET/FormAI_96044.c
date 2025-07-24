//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <string.h>

// function to convert decimal to hexadecimal
void decimalToHex(int num) {
    // code to convert decimal to hexadecimal
}

// function to convert hexadecimal to decimal
void hexToDecimal(char* hex) {
    // code to convert hexadecimal to decimal
}

int main() {
    int choice;
    char hexNum[100];

    while (1) {
        // menu to choose conversion type
        printf("\nChoose conversion type:\n");
        printf("1. Decimal to Hexadecimal\n");
        printf("2. Hexadecimal to Decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // code for decimal to hexadecimal conversion
                break;
            case 2:
                // code for hexadecimal to decimal conversion
                break;
            case 3:
                exit(0);    // exit the program
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <ctype.h> // for tolower() and isxdigit()

int main() {
    printf("Welcome to Hexadecimal to Decimal Converter!\n");
    
    while (1) {
        char hex[10];
        printf("\nEnter a hexadecimal number (or q to quit): ");
        scanf("%s", hex);
        
        // handle quitting condition
        if (tolower(hex[0]) == 'q') {
            printf("Goodbye!\n");
            break;
        }
        
        // check if input is valid hexadecimal number
        int i;
        for (i = 0; hex[i] != '\0'; i++) {
            if (!isxdigit(hex[i])) {
                printf("Invalid input. Please enter a hexadecimal number.\n");
                break;
            }
        }
        if (hex[i] != '\0') {
            continue; // prompt again
        }
        
        // convert hexadecimal number to decimal number
        int dec = 0;
        int base = 1;
        for (i = strlen(hex) - 1; i >= 0; i--) {
            int digit;
            if (isdigit(hex[i])) {
                digit = hex[i] - '0';
            } else {
                digit = tolower(hex[i]) - 'a' + 10;
            }
            dec += digit * base;
            base *= 16;
        }
        
        // print result
        printf("The decimal value of %s is %d.\n", hex, dec);
    }
    
    return 0;
}
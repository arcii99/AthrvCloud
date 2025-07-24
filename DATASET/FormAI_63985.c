//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int integer;
    char hex[100];

    printf("Please enter an integer: ");
    scanf("%d", &integer);
    
    sprintf(hex, "%X", integer);
    printf("Hexadecimal conversion of %d is: %s\n", integer, hex);

    printf("\nDo you want to convert from Hexadecimal to Integer? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        char hexValue[100];
        int intValue;

        printf("\nEnter a Hexadecimal value: ");
        scanf("%s", &hexValue);

        intValue = (int)strtol(hexValue, NULL, 16); 

        printf("Integer conversion of %s is: %d\n", hexValue, intValue);
    }

    return 0;
}
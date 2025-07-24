//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>
#include <string.h>

void convertToHex(char*);

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    str[strcspn(str, "\n")] = 0; // remove newline character from input

    convertToHex(str);

    return 0;
}

void convertToHex(char* str)
{
    int len = strlen(str);
    int i;

    printf("Hex representation of %s is: ", str);

    for(i = 0; i < len; i++)
    {
        printf("%02X ", str[i]); // %02X formats the output to print 2 characters and pads with 0 if necessary
    }
}
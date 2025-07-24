//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#define MAX 10

void convertToRGB(int, int, int);
void convertToHex(int, int, int);

int main() 
{
    int option;
    int r, g, b;
    printf("Please choose an option: \n");
    printf("1. Convert from RGB to Hex\n");
    printf("2. Convert from Hex to RGB\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option) 
    {
        case 1:
            printf("Enter R value: ");
            scanf("%d", &r);
            printf("Enter G value: ");
            scanf("%d", &g);
            printf("Enter B value: ");
            scanf("%d", &b);
            convertToHex(r, g, b);
            break;
        case 2:
            char hex[MAX];
            printf("Enter a hexadecimal value: ");
            scanf("%s", hex);
            sscanf(hex, "%02x%02x%02x", &r, &g, &b);
            convertToRGB(r, g, b);
            break;
    }
    return 0;
}

void convertToRGB(int r, int g, int b) 
{
    printf("Red = %d, Green = %d, Blue = %d", r, g, b);
}

void convertToHex(int r, int g, int b)
{
    char hex[MAX];
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    printf("Hexadecimal value is: %s", hex);
}
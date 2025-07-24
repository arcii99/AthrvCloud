//FormAI DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

//Function to convert Color Code to its Hexadecimal equivalent
void ColorCodeConverter(char* colorCode)
{
    char* hexCode;
    hexCode = (char*)malloc(sizeof(char) * 7);
    hexCode[0] = '#';
    int i, j = 1;
    char temp;
    for (i = 0; colorCode[i] != '\0'; i++) {
        if (isdigit(colorCode[i])) {
            hexCode[j] = colorCode[i];
            j++;
        }
        else if (colorCode[i] >= 'a' && colorCode[i] <= 'z') {
            hexCode[j] = colorCode[i] - 32;
            j++;
        }
        else if (colorCode[i] >= 'A' && colorCode[i] <= 'Z') {
            hexCode[j] = colorCode[i];
            j++;
        }
        else {
            printf("\nInvalid Color Code format.\n");
            return;
        }
    }
    hexCode[j] = '\0';
    printf("\nHexadecimal Equivalent : %s\n", hexCode);
}

//Main function
int main()
{
    char* colorCode;
    colorCode = (char*)malloc(sizeof(char) * 7);
    printf("Enter the Color Code (RGB format ex: R22GbB3): ");
    scanf("%s", colorCode);
    ColorCodeConverter(colorCode);
    free(colorCode);
    return 0;
}
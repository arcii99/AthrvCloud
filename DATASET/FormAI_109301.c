//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hexCode[8], redCode[3], greenCode[3], blueCode[3];
    printf("Enter the 6 digit color code in hexadecimal format: ");
    scanf("%s", hexCode);
    int len = strlen(hexCode);
    if (len != 6) {
        printf("Please enter a valid 6 digit color code.\n");
        exit(0);
    }
    strncpy(redCode, hexCode, 2);
    strncpy(greenCode, hexCode + 2, 2);
    strncpy(blueCode, hexCode + 4, 2);
    redCode[2] = '\0';
    greenCode[2] = '\0';
    blueCode[2] = '\0';
    int redDec = strtol(redCode, NULL, 16);
    int greenDec = strtol(greenCode, NULL, 16);
    int blueDec = strtol(blueCode, NULL, 16);
    printf("R: %d\nG: %d\nB: %d\n", redDec, greenDec, blueDec);
    return 0;
}
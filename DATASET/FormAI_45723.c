//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToHex(char *color) {
    int r, g, b;
    sscanf(color, "#%02x%02x%02x", &r, &g, &b);
    printf("Color in Decimal: %d, %d, %d\n", r, g, b);
}

void convertToDecimal(char *color) {
    char hex[7]="";
    int r, g, b;
    sscanf(color, "%d,%d,%d", &r, &g, &b);
    sprintf(hex, "%02X%02X%02X", r, g, b);
    printf("Color in Hex: #%s\n", hex);
}

int main() {
    char color[8];
    char choice[2];
    printf("Enter a color in hex or decimal format: ");
    scanf("%s", color);

    if (strstr(color, "#") != NULL) {
        printf("You have entered a hex color.\n");
        printf("Convert to decimal? (Y/N): ");
        scanf("%s", choice);
        if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
            convertToHex(color);
        }
    }
    else {
        printf("You have entered a decimal color.\n");
        printf("Convert to hex? (Y/N): ");
        scanf("%s", choice);
        if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
            convertToDecimal(color);
        }
    }

    return 0;
}
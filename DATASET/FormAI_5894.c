//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <string.h>

void convertRGBtoHex(int r, int g, int b) {
    char hex[7];
    sprintf(hex, "%02X%02X%02X", r, g, b);
    printf("Hex code is #%s\n", hex);
}

void convertHextoRGB(char* hex) {
    int r, g, b;
    sscanf(hex, "%02X%02X%02X", &r, &g, &b);
    printf("RGB code is (%d, %d, %d)\n", r, g, b);
}

int main() {
    int choice = 0;
    printf("Welcome to Color Code Converter!\n");
    while(choice != 3) {
        printf("\nChoose an option:\n1. Convert RGB to Hex\n2. Convert Hex to RGB\n3. Exit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            int r, g, b;
            printf("\nEnter values for Red, Green and Blue separated by spaces:\n");
            scanf("%d %d %d", &r, &g, &b);
            convertRGBtoHex(r, g, b);
        }
        else if(choice == 2) {
            char hex[7];
            printf("\nEnter a 6 digit Hex code (without '#'):\n");
            scanf("%s", hex);
            convertHextoRGB(hex);
        }
        else if(choice == 3) {
            printf("\nGoodbye!\n");
            break;
        }
        else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
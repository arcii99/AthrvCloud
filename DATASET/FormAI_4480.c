//FormAI DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hex_to_rgb(char *hex_code) {
    int r, g, b;
    sscanf(hex_code, "%02x%02x%02x", &r, &g, &b);
    printf("RGB Color Code : (%d,%d,%d)\n", r, g, b);
}

void rgb_to_hex(int r, int g, int b) {
    char hex_code[7];
    sprintf(hex_code, "#%02x%02x%02x", r, g, b);
    printf("Hexadecimal Color Code : %s\n", hex_code);
}

int main() {
    int choice;
    char hex_code[7];
    int r, g, b;
    printf("Welcome to C Color Code Converter Program\n");
    while(1) {
        printf("Select your choice : \n");
        printf("1. Convert Hexadecimal Color Code to RGB\n");
        printf("2. Convert RGB Color Code to Hexadecimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter Hexadecimal Color Code : ");
                scanf("%s", hex_code);
                hex_to_rgb(hex_code);
                break;
            case 2:
                printf("Enter RGB Color Code : ");
                scanf("%d,%d,%d", &r, &g, &b);
                rgb_to_hex(r, g, b);
                break;
            case 3:
                printf("Thank you for using Color Code Converter Program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
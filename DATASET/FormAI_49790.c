//FormAI DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Function to convert RGB color code to hexadecimal color code
*/
char* RGBToHex(int r, int g, int b) {
    char* hex = (char*) malloc(sizeof(char) * 7);
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    return hex;
}

/*
 * Function to convert hexadecimal color code to RGB color code
*/
void HexToRGB(char* hex, int* r, int* g, int* b) {
    sscanf(hex, "#%02x%02x%02x", r, g, b);
}

int main() {
    int option;
    do {
        printf("1. Convert RGB color code to hexadecimal color code\n");
        printf("2. Convert hexadecimal color code to RGB color code\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                int r, g, b;
                printf("Enter RGB color code (0 to 255): ");
                scanf("%d %d %d", &r, &g, &b);

                char* hex = RGBToHex(r, g, b);
                printf("Hexadecimal color code: %s\n", hex);
                free(hex);
                break;
            }

            case 2: {
                char hex[7];
                int r, g, b;
                printf("Enter hexadecimal color code (example: #ff69b4): ");
                scanf("%s", hex);

                HexToRGB(hex, &r, &g, &b);
                printf("RGB color code: (%d, %d, %d)\n", r, g, b);
                break;
            }

            case 3: {
                printf("Goodbye!\n");
                break;
            }

            default: {
                printf("Invalid option!\n");
            }
        }
    } while(option != 3);

    return 0;
}
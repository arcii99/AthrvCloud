//FormAI DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <string.h>

// Function to convert RGB to hexadecimal color code
void rgb_to_hex(int r, int g, int b)
{
    char hex[7];
    sprintf(hex, "%02X%02X%02X", r, g, b);
    printf("The hexadecimal code is: #%s\n", hex);
}

// Function to convert hexadecimal color code to RGB
void hex_to_rgb(char* hex)
{
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);
    printf("The RGB code is: (%d, %d, %d)\n", r, g, b);
}

int main()
{
    int choice;
    printf("Welcome to the Color Code Converter\n");
    do {
        // Display menu
        printf("\nChoose an option:\n");
        printf("1. Convert RGB to hexadecimal\n");
        printf("2. Convert hexadecimal to RGB\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Input RGB values
                int red, green, blue;
                printf("Input the Red, Green, and Blue values (0-255): ");
                scanf("%d%d%d", &red, &green, &blue);
                if (red < 0 || green < 0 || blue < 0 ||
                    red > 255 || green > 255 || blue > 255) {
                    printf("Invalid RGB values, please try again.\n");
                } else {
                    rgb_to_hex(red, green, blue);
                }
                break;
            case 2:
                // Input hexadecimal value
                char hex[7];
                printf("Input the hexadecimal code (with or without #): ");
                scanf("%s", hex);
                if (strlen(hex) != 6 && strlen(hex) != 7) {
                    printf("Invalid hexadecimal code, please try again.\n");
                } else {
                    if (hex[0] == '#') {
                        hex_to_rgb(hex+1);
                    } else {
                        hex_to_rgb(hex);
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
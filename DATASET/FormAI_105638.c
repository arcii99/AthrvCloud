//FormAI DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>

int main() {
    int red, green, blue;
    char choice;
    int hex_value;
    printf("Enter RGB values (0-255) separated by spaces: ");
    scanf("%d %d %d", &red, &green, &blue);

    printf("Do you want to convert to HEX? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        hex_value = (red * 65536) + (green * 256) + blue;
        printf("Hex value: #%06X\n", hex_value);
    } else {
        printf("RGB values: %d %d %d\n", red, green, blue);
    }

    return 0;
}
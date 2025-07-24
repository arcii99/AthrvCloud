//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    char mode;
    printf("Enter conversion mode: ");
    scanf("%c", &mode);

    if (mode == 'h') {
        // convert hex color code to RGB
        char hex[7];
        printf("Enter hex color code: ");
        scanf("%s", hex);

        int r, g, b;
        sscanf(hex, "%02x%02x%02x", &r, &g, &b);
        printf("RGB color code: (%d,%d,%d)\n", r, g, b);
    } else if (mode == 'r') {
        // convert RGB color code to hex
        int r, g, b;
        printf("Enter RGB color code (separated by spaces): ");
        scanf("%d %d %d", &r, &g, &b);

        printf("Hex color code: #%02X%02X%02X\n", r, g, b);    
    } else {
        // invalid mode entered
        printf("Invalid mode entered\n");
    }

    return 0;
}
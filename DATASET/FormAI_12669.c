//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>

int main() {
    int r=0, g=0, b=0, c_code=0;

    printf("Enter Red (0-255): ");
    scanf("%d", &r);
    printf("Enter Green (0-255): ");
    scanf("%d", &g);
    printf("Enter Blue (0-255): ");
    scanf("%d", &b);

    // Convert RGB values to C color code
    c_code = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);

    printf("C color code: 0x%06x\n", c_code);

    return 0;
}
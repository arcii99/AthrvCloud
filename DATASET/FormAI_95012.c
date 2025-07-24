//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex[7];    // stores the hex color code
    int dec[3];     // stores the RGB values in decimal form

    printf("Enter a 6-digit hex color code: ");
    scanf("%s", hex);

    // convert the hex color code to 3 decimal values
    int i;
    for (i = 0; i < 3; i++) {
        dec[i] = (int) strtol(&hex[i*2], NULL, 16);
    }

    printf("\nRGB values: %d, %d, %d\n", dec[0], dec[1], dec[2]);

    return 0;
}
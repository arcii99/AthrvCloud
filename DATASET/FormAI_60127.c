//FormAI DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // Declare variables
    int rgb[3];
    char hex[7] = "#";
    
    // Get input from user
    printf("Enter RGB values (separated by space): ");
    scanf("%d %d %d", &rgb[0], &rgb[1], &rgb[2]);

    // Convert RGB to hex
    for (int i = 0; i < 3; i++) {
        int remainder, quotient = rgb[i];
        while (quotient != 0) {
            remainder = quotient % 16;
            if (remainder < 10) {
                hex[(i*2)+1] = remainder + '0';
            } else {
                hex[(i*2)+1] = remainder + 55;
            }
            quotient = quotient / 16;
        }
        if (rgb[i] < 16) {
            hex[i*2+1] = '0';
        }
    }

    // Print results to user
    printf("Hex Code: %s", hex);

    return 0;
}
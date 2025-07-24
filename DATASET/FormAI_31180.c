//FormAI DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    int red, green, blue;
    float cyan, magenta, yellow, black;

    printf("Enter RGB values (0-255) separated by space: ");
    scanf("%d %d %d", &red, &green, &blue);

    // Convert RGB to CMYK
    cyan = 1 - (red / 255.0);
    magenta = 1 - (green / 255.0);
    yellow = 1 - (blue / 255.0);

    float minCMY = cyan < magenta ? cyan : magenta;
    black = minCMY < yellow ? minCMY : yellow;

    cyan = (cyan - black) / (1 - black);
    magenta = (magenta - black) / (1 - black);
    yellow = (yellow - black) / (1 - black);

    // Convert CMYK to C Color Code
    int colorCode = ((int)(cyan * 100 + 0.5) * 65536) + ((int)(magenta * 100 + 0.5) * 256) + (int)(yellow * 100 + 0.5);

    printf("\nCMYK values: C=%.2f M=%.2f Y=%.2f K=%.2f\n", cyan*100, magenta*100, yellow*100, black*100);
    printf("C Color Code: #%06X", colorCode);

    return 0;
}
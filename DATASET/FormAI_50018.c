//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mathematical
#include <stdio.h>

int main() {
    // define variables
    int red, green, blue;
    float cyan, magenta, yellow, black;

    // get RGB values from user input
    printf("Enter red value (0-255): ");
    scanf("%d", &red);
    printf("Enter green value (0-255): ");
    scanf("%d", &green);
    printf("Enter blue value (0-255): ");
    scanf("%d", &blue);

    // convert from RGB to CMYK
    float redPercent = (float)red / 255;
    float greenPercent = (float)green / 255;
    float bluePercent = (float)blue / 255;
    black = 1 - fmax(fmax(redPercent, greenPercent), bluePercent);
    cyan = (1 - redPercent - black) / (1 - black);
    magenta = (1 - greenPercent - black) / (1 - black);
    yellow = (1 - bluePercent - black) / (1 - black);

    // convert from CMYK to RGB
    red = (1 - cyan) * (1 - black) * 255;
    green = (1 - magenta) * (1 - black) * 255;
    blue = (1 - yellow) * (1 - black) * 255;

    // print out results
    printf("\nRGB: (%d, %d, %d)\n", red, green, blue);
    printf("CMYK: (%.2f%%, %.2f%%, %.2f%%, %.2f%%)\n",
           cyan * 100, magenta * 100, yellow * 100, black * 100);

    return 0;
}
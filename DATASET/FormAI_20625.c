//FormAI DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the wackiest C Color Code Converter around!\n");
    printf("Enter a color code in hex format (#RRGGBB) and this program will convert it into RGB notation!\n");

    char hexCode[8];
    scanf("%s", hexCode);
    getchar();  // flush out newline character from input buffer

    if (hexCode[0] != '#') {
        printf("Oops! You forgot to enter the '#' symbol in the color code!\n");
        return 1;
    }

    // convert hex string to integer values for each color component
    int red = strtol(hexCode+1, NULL, 16) >> 16;
    int green = (strtol(hexCode+1, NULL, 16) >> 8) & 0xff;
    int blue = strtol(hexCode+1, NULL, 16) & 0xff;

    printf("The RGB color code for %s is (%d, %d, %d)\n", hexCode, red, green, blue);
    printf("But wait, that's not all we can do!\n");

    printf("Enter a color code in RGB format (RRGGBB) and we'll convert it to a hex code for you!\n");

    char rgbCode[7];
    scanf("%s", rgbCode);
    getchar();  // flush out newline character from input buffer

    // convert RGB string to integer values for each color component
    red = atoi(rgbCode) >> 16;
    green = (atoi(rgbCode) >> 8) & 0xff;
    blue = atoi(rgbCode) & 0xff;

    sprintf(hexCode, "#%02X%02X%02X", red, green, blue);  // format hex code string

    printf("The hex color code for %s is %s\n", rgbCode, hexCode);
    printf("We've done it! Give yourself a pat on the back for participating in this madcap program.\n");
    
    return 0;
}
//FormAI DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>

int main() {
    int hexCode;
    char c;

    printf("Enter a color code in hexadecimal format: ");
    scanf("%x", &hexCode);

    printf("\n");

    printf("The RGB code for this color is: ");
    printf("%d, %d, %d", (hexCode >> 16) & 0xFF, (hexCode >> 8) & 0xFF, hexCode & 0xFF);

    printf("\n");

    if (hexCode >= 0xFA8072 && hexCode <= 0xFFA07A) {
        c = 'P';
    } else if (hexCode >= 0x008000 && hexCode <= 0x00FF00) {
        c = 'G';
    } else if (hexCode >= 0x000080 && hexCode <= 0x0000FF) {
        c = 'B';
    } else if (hexCode >= 0xFFFFF0 && hexCode <= 0xFFFFFA) {
        c = 'Y';
    } else if (hexCode >= 0xFFD700 && hexCode <= 0xFFFF00) {
        c = 'O';
    } else if (hexCode >= 0x800080 && hexCode <= 0xFF00FF) {
        c = 'P';
    } else if (hexCode >= 0x800000 && hexCode <= 0xFF0000) {
        c = 'R';
    } else {
        c = 'N';
    }

    printf("\nThe color is in the %c color family.", c);

    return 0;
}
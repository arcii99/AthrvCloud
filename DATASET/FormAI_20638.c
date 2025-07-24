//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char code[7];

    printf("Oh, Romeo, oh Romeo...\n");
    printf("What is the color code that thou seek?\n");

    scanf("%s", code);

    if (strlen(code) != 6) {
        printf("Oh dear, this code of yours seems to be invalid.\n");
        return 1;
    }

    int red, green, blue;

    sscanf(code, "%2x%2x%2x", &red, &green, &blue);

    printf("Ah, I see now, your code translates to:\n");
    printf("Red: %d\nGreen: %d\nBlue: %d\n", red, green, blue);

    return 0;
}
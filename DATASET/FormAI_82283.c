//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: invasive
#include <stdio.h>

int main() {
    char character = 'M';
    char blank = ' ';
    char newline = '\n';

    // Low-resolution Mario character
    char mario[5][5] = {
        {blank, blank, character, character, blank},
        {blank, character, blank, character, character},
        {blank, character, character, character, blank},
        {blank, character, blank, blank, blank},
        {blank, character, blank, blank, blank}
    };

    // Print the character
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c", mario[i][j]);
        }
        printf("%c", newline);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter your text: ");
    char text[100];
    fgets(text, 100, stdin);

    int length = strlen(text);
    int i, j;

    printf("\n");

    for (i = 0; i < length; i++) {
        char c = text[i];

        if (c == ' ') {
            printf("          ");
        }
        else if (c == '\n') {
            printf("\n");
        } else {
            for (j = 0; j < 8; j++) {
                if (c & (1 << (7 - j))) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }

        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}
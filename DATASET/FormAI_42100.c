//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

void print_ascii_art(char *text) {
    int i, j, len;
    char art[95][MAX_WIDTH] = {
        // Enter ASCII art here
    };
    len = strlen(text);
    for (i = 0; i < 95; i++) {
        for (j = 0; j < len; j++) {
            int index = text[j] - 32;
            if (index >= 0 && index < 95) {
                printf("%c", art[index][i]);
            }
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    print_ascii_art(text);
    return 0;
}
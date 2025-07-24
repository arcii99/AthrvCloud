//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WIDTH 32
#define HEIGHT 32

void generate_pixelart(char ch, int color) {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(tolower(ch) - 'a' == i%26 && color == j%8) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    char ch;
    int color;

    if(argc >= 2) {
        ch = *argv[1];
    } else {
        printf("Enter a character: ");
        scanf("%c", &ch);
    }

    if(argc >= 3) {
        color = atoi(argv[2]);
    } else {
        printf("Enter a color (0-7): ");
        scanf("%d", &color);
    }

    generate_pixelart(ch, color);

    return 0;
}
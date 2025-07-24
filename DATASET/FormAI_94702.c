//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 20

char text[HEIGHT][WIDTH];

int main(void) {
    // get input text
    printf("Enter text (max %d characters):\n", WIDTH * HEIGHT);
    
    int c;
    int i = 0;
    while ((c = getchar()) != EOF && i < WIDTH * HEIGHT) {
        if (c == '\n') {
            break;
        }
        text[i / WIDTH][i % WIDTH] = c;
        i++;
    }
    
    // print ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            char ch = text[y][x];
            if (ch >= 'A' && ch <= 'Z') {
                printf("*");
            } else if (ch >= 'a' && ch <= 'z') {
                printf("#");
            } else if (ch >= '0' && ch <= '9') {
                printf("=");
            } else if (ch == ' ') {
                printf(" ");
            } else {
                printf("+");
            }
        }
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}
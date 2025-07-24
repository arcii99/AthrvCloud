//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

void generate_art(int pixels[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            pixels[i][j] = rand() % 2;
        }
    }
}

void display_art(int pixels[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (pixels[i][j] == 1) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int pixels[ROW][COL];
    generate_art(pixels);
    display_art(pixels);
    
    return 0;
}
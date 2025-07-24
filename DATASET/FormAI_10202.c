//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_pixel_art(int matrix[20][20], int height) {
    char pixel;
    char colors[] = {'*', '#', '$', '%', '&', '!'};
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < 20; j++) {
            pixel = colors[matrix[i][j]];
            printf("%c ", pixel);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    int pixel_art[20][20];
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            pixel_art[i][j] = rand() % 6;
        }
    }
    
    printf("Sherlock Holmes-style Pixel Art:\n");
    print_pixel_art(pixel_art, 20);
    
    return 0;
}
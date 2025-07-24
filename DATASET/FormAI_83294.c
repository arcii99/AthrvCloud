//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_pixel_art(char **pixel_art, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixel_art[i][j]);
        }
        printf("\n");
    }
}

char **generate_pixel_art(int height, int width) {
    char **pixel_art = (char **)malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        pixel_art[i] = (char *)malloc(sizeof(char) * width);
    }

    srand(time(NULL));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixel_art[i][j] = rand() % 2 == 0 ? 'X' : '-';
        }
    }

    return pixel_art;
}

int main() {
    int height, width;
    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);
    printf("\n");

    char **pixel_art = generate_pixel_art(height, width);
    print_pixel_art(pixel_art, height, width);

    for (int i = 0; i < height; i++) {
        free(pixel_art[i]);
    }
    free(pixel_art);

    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>

int main() {
    int width, height, color;
    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    printf("Choose a color to use (1 = RED, 2 = GREEN, 3 = BLUE): ");
    scanf("%d", &color);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(color == 1) {
                printf("\033[31m");
            } else if(color == 2) {
                printf("\033[32m");
            } else if(color == 3) {
                printf("\033[34m");
            }
            printf("\u2588");
        }
        printf("\n");
    }
    return 0;
}
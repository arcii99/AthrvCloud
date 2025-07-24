//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: grateful
#include <stdio.h>

int main() {
    int x, y, color;
    printf("Enter the size of the canvas (X and Y values): ");
    scanf("%d %d", &x, &y);
    printf("Enter the color (0-255): ");
    scanf("%d", &color);
    printf("Here is your pixel art:\n");

    // creating the art
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            if(j % 2 == 0 && i % 2 == 0) {
                printf("\033[38;5;%dm*\033[0m", color);
            } else if(j % 2 != 0 && i % 2 == 0) {
                printf("\033[38;5;%dm#\033[0m", color);
            } else if(j % 2 == 0 && i % 2 != 0) {
                printf("\033[38;5;%dm#\033[0m", color);
            } else {
                printf("\033[38;5;%dm*\033[0m", color);
            }
        }
        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printPixel(char *color) {
    printf("\033[48;2;%sm  \033[0m", color);
}

int main() {
    srand(time(NULL));
    int width, height;
    int numColors;
    char **colors;

    printf("Enter width of canvas in pixels: ");
    scanf("%d", &width);
    printf("Enter height of canvas in pixels: ");
    scanf("%d", &height);
    printf("Enter number of colors to use: ");
    scanf("%d", &numColors);

    colors = malloc(numColors * sizeof(char *));
    for(int i = 0; i < numColors; i++) {
        colors[i] = malloc(8 * sizeof(char));
        printf("Enter color %d in the format R,G,B: ", i+1);
        scanf("%s", colors[i]);
    }

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int colorIndex = rand() % numColors;
            printPixel(colors[colorIndex]);
        }
        printf("\n");
    }

    for(int i = 0; i < numColors; i++) {
        free(colors[i]);
    }
    free(colors);

    return 0;
}
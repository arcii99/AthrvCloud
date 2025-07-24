//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mind-bending
#include <stdio.h>

int main() {
    printf("Welcome to the Mind-Bending ASCII Art Generator!\n");

    int height, width;
    printf("Enter the height of your ASCII art: ");
    scanf("%d", &height);
    printf("Enter the width of your ASCII art: ");
    scanf("%d", &width);

    printf("\n");

    char art[height][width];

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            art[i][j] = ' ';
        }
    }

    // Generate random ASCII art
    int x, y;
    for (i = 0; i < height * width; i++) {
        x = rand() % height;
        y = rand() % width;
        art[x][y] = (rand() % 95) + 32;
    }

    // Print the generated ASCII art
    printf("Here is your mind-bending ASCII art:\n\n");

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    return 0;
}
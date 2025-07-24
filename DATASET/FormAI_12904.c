//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>

int main() {
    int height, width, center;
    printf("Enter the height: ");
    scanf("%d", &height);
    width = 2 * height - 1;
    center = width / 2;

    char pattern[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == center || i == 0 || (i == height - 1 && j % 2 == 0)) {
                pattern[i][j] = '*';
            } else {
                pattern[i][j] = ' ';
            }
        }
    }

    for (int i = 1; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == j || i == width - j - 1) {
                pattern[i][j] = '*';
            }
        }
    }

    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c ", pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}
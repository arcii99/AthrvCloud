//FormAI DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>

void generateFractal(int level, int x, int y, int size, char canvas[][70]) {
    if (level == 0) {
        canvas[x][y] = '*';
        return;
    }

    int newSize = size / 3;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (i == x + newSize && j == y + newSize) {
                for (int k = i - newSize; k < i + newSize; k++) {
                    for (int l = j - newSize; l < j + newSize; l++) {
                        canvas[k][l] = ' ';
                    }
                }
            } else {
                generateFractal(level - 1, i, j, newSize, canvas);
            }
        }
    }
}

int main() {
    char canvas[70][70];

    for (int i = 0; i < 70; i++) {
        for (int j = 0; j < 70; j++) {
            canvas[i][j] = '#';
        }
    }

    generateFractal(4, 0, 0, 70, canvas);

    for (int i = 0; i < 70; i++) {
        for (int j = 0; j < 70; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }

    return 0;
}
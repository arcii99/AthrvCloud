//FormAI DATASET v1.0 Category: Pattern printing ; Style: brave
#include<stdio.h>

void printStar() {
    printf("*");
}

void printSpace() {
    printf(" ");
}

void pattern() {
    int height = 10;
    int width = 9;

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            if (i == 1 && (j == 1 || j == width) ||
                i == height / 2 + 1 && (j == 1 || j == width)) {
                printStar();
            } else if (j == 1) {
                printStar();
            } else if (i == 1 || i == height || i == height / 2 + 1) {
                printStar();
            } else if (i < height / 2 + 1 && j == width - i + 1) {
                printStar();
            } else if (i > height / 2 + 1 && j == i) {
                printStar();
            } else {
                printSpace();
            }
        }
        printf("\n");
    }
}

int main() {
    pattern();
}
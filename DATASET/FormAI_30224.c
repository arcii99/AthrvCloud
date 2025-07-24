//FormAI DATASET v1.0 Category: Pattern printing ; Style: unmistakable
#include <stdio.h>

int main() {
    int height, width, i, j, k;

    printf("Enter the width of the C pattern: ");
    scanf("%d", &width);
    printf("\nEnter the height of the C pattern: ");
    scanf("%d", &height);

    for (i = 0; i < height; i++) {
        printf("*");
        for (j = 0; j < width-1; j++) {
            if (i == 0 || i == height-1) {
                printf("*");
            } else if (j == width-2 && i <= height/2) {
                printf("*");
            } else if (i == height/2) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
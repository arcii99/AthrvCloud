//FormAI DATASET v1.0 Category: Pattern printing ; Style: unmistakable
#include <stdio.h>

int main() {
    int height, width;
    printf("Enter the height of the pattern: ");
    scanf("%d", &height);
    printf("Enter the width of the pattern: ");
    scanf("%d", &width);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(i == 0 || i == height - 1 || j == 0 || j == width - 1 || i == j || i + j == height - 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Pattern printing ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int height, width;
    printf("Enter the height and width of the pattern: ");
    scanf("%d %d", &height, &width);

    if (height < 1 || width < 1) {
        printf("Invalid input, height and width must be positive integers!\n");
        return 1;
    }

    int currentRow = 1;
    while (currentRow <= height) {
        int currentCol = 1;
        while (currentCol <= width) {
            if (currentRow == 1 || currentRow == height || currentCol == 1 || currentCol == width) {
                printf("* ");
            } else if (currentRow == currentCol || currentRow + currentCol == height + 1) {
                printf("+ ");
            } else {
                printf("- ");
            }
            currentCol++;
        }
        printf("\n");
        currentRow++;
    }
    return 0;
}
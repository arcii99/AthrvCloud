//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>
int main() {
    int height, width, i, j, counter = 0;
    printf("Welcome to the C Pattern Printer!\n");
    printf("Enter the height of the pattern (odd numbers only): ");
    scanf("%d", &height);
    printf("Enter the width of the pattern (odd numbers only): ");
    scanf("%d", &width);
    if (height % 2 == 0 || width % 2 == 0) {
        printf("Invalid input. Both height and width must be odd numbers.\n");
        return 0;
    }
    int halfHeight = (height + 1) / 2;
    int halfWidth = (width + 1) / 2;
    for (i = 1; i <= height; i++) {
        for (j = 1; j <= width; j++) {
            if (i == 1 || i == height) {
                printf("* ");
            }
            else if (i == halfHeight) {
                printf("*");
                counter++;
                if (counter == halfWidth) {
                    printf(" ");
                    counter = 0;
                }
            }
            else {
                if (j == 1 || j == width) {
                    printf("* ");
                }
                else {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
    printf("Pattern printed successfully!\n");
    return 0;
}
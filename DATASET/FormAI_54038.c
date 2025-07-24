//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

int main() {
    printf("Oh happy day! Let's print a unique pattern!\n\n");

    int rows, cols, currentRow, currentCol, counter = 0;
    printf("Enter the number of rows you want: ");
    scanf("%d", &rows);
    printf("Enter the number of columns you want: ");
    scanf("%d", &cols);

    for (currentRow = 1; currentRow <= rows; currentRow++) {
        for (currentCol = 1; currentCol <= cols; currentCol++) {
            if (currentRow == 1 || currentRow == rows || currentCol == 1 || currentCol == cols) {
                printf("C ");
                counter++;
            } else if (currentRow == currentCol) {
                printf("1 ");
                counter++;
            } else if (currentRow > currentCol) {
                printf("L ");
                counter++;
            } else {
                printf("V ");
                counter++;
            }
        }
        printf("\n");
    }
    
    printf("\nYaaay! We made it to the end of the pattern! We printed %d shapes.\n", counter);

    return 0;
}
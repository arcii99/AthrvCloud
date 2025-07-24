//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, i, j, k, count = 1, space;
    printf("Enter the number of rows you want in the pattern: ");
    scanf("%d", &rows);
    int center = (rows + rows%2)/2;
    int reversed = rows-2;
    for (i = 1; i <= rows; i++) {
        if(i <= center) {
            for (j = 1, space = rows - i; j <= space; ++j) {
                printf("  ");
            }
            for (k = i * 2 - 1; k > 0; --k) {
                printf("%d ", count);
                ++count;
            }
            printf("\n");
        }
        else {
            if(i % 2 == 0) reversed--;
            for (j = 1, space = rows - reversed - i%2; j <= space; ++j) {
                printf("  ");
            }
            for (k = reversed * 2 - i%2 + 1; k > 0; --k) {
                printf("%d ", count);
                ++count;
            }
            printf("\n");
        }
    }
    return 0;
}
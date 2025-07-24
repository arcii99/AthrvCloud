//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

int main() {
    int rows = 5;
    int cols = 5;

    char c = 'A';
    int num = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%c ", c);
                c++;
            } else if (i == j) {
                printf("%d ", num);
                num++;
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}
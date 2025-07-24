//FormAI DATASET v1.0 Category: Educational ; Style: puzzling
#include <stdio.h>

int main() {
    int x = 1;
    int y = 0;

    while (x < 10) {
        printf("%d ", x);
        x++;
        y += x;
    }

    printf("\n");
    printf("The sum is %d", y);

    return 0;
}
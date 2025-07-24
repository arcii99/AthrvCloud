//FormAI DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include <stdio.h>

int main() {
    int size;
    printf("Enter a size: ");
    scanf("%d", &size);
    int midpoint = size / 2;
    for(int row = 0; row < size; row++) {
        for(int column = 0; column < size; column++) {
            if(column == 0 || row == 0 || row == size - 1 || row == midpoint || (column == midpoint && row < midpoint)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
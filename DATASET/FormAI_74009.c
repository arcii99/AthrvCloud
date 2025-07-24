//FormAI DATASET v1.0 Category: Pattern printing ; Style: optimized
#include <stdio.h>

int main() {
    int row, col, mid;
    printf("Enter the size of the triangle: ");
    scanf("%d", &mid);

    row = col = mid;

    for(int i = 1; i <= row; i++) { // First pyramid
        for(int j = 1; j <= col; j++) {
            if(j == mid || j == col || i == row) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        mid--;
        col++;
        printf("\n");
    }

    mid = row = col / 2 + 1;

    for(int i = 1; i <= row; i++) { // Second pyramid
        for(int j = 1; j <= col; j++) {
            if(j == mid || j == col || i == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        mid++;
        col--;
        printf("\n");
    }

    return 0;
}
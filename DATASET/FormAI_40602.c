//FormAI DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>

int main() {
    int row, col, num;

    printf("Enter the number of rows (odd number): ");
    scanf("%d", &num);

    if(num % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 0;
    }

    for(row = 1; row <= num; row++) {
        for(col = 1; col <= num; col++) {
            if(row == (num / 2) + 1 || col == (num / 2) + 1) {
                printf("* ");
            } else if(row == col || row + col == num + 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}
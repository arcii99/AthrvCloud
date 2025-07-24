//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main() {
  printf("Let's print a unique C pattern:\n\n");

  int row, col, mid;
    // User input for pattern size
    printf("Enter the size of the pattern: ");
    scanf("%d", &row);
    col = row;
    mid = (row / 2) + 1;

    // Loop for creating the pattern
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            if(i == 1 || i == mid || i == row) {
                printf("*");
            } else if(j == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

  return 0;
}
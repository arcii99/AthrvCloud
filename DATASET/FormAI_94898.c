//FormAI DATASET v1.0 Category: Pattern printing ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to the C Pattern printing program!\n");

    int rows;
    printf("Enter the number of rows you want to print: ");
    scanf("%d", &rows);
    printf("\n");

    if(rows < 1) {
        printf("Invalid input. Number of rows must be greater than 0.\n");
    } else {
        printf("Here is your %d-row pattern:\n", rows);
        
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= i; j++) {
                printf("%d", j);
            }
            for(int k = i+1; k <= rows; k++) {
                printf(" ");
            }
            for(int m = rows-i; m >= 1; m--) {
                printf(" ");
            }
            for(int n = i; n >= 1; n--) {
                printf("%d", n);
            }
            printf("\n");
        }
    }
    return 0;
}
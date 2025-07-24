//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include <stdio.h>

int main() {
    //declare variables
    int rows, i, j, k, l;

    printf("Wow, let's print a stunning pattern of stars and dashes!\n");
    printf("Enter the number of rows you want:");
    scanf("%d", &rows);

    //print pattern using nested loop
    for (i = 1; i <= rows; i++) {
        
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        
        for (k = rows - i; k >= 1; k--) {
            printf("-");
        }

        for (l = rows - i; l >= 1; l--) {
            printf("-");
        }
        
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        
        printf("\n");
    }

    printf("Oh my! Isn't that mesmerizing?\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Pattern printing ; Style: light-weight
#include <stdio.h>

int main() {
    int rows, i, j, k;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    //Printing C pattern
    printf("* * * * * * *\n");
    for(i=2; i<rows; i++) {
        printf("*\n");
    }
    for(j=1; j<=rows; j++) {
        printf("* ");
    }
    printf("\n"); 
    return 0;
}
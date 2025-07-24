//FormAI DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

int main() {
    printf("I am a C program printing a unique C pattern!\n");

    int rows, i, j, k;
    printf("Enter the number of rows you want in the pattern: ");
    scanf("%d", &rows);

    for(i=1; i<=rows; i++) {
        for(j=rows; j>=i; j--) {
            printf("*");
        }
        for(k=1; k<=(2*i-2); k++) {
            printf("C");
        }
        printf("\n");
    }

    for(i=rows-1; i>=1; i--) {
        for(j=rows; j>=i; j--) {
            printf("*");
        }
        for(k=1; k<=(2*i-2); k++) {
            printf("C");
        }
        printf("\n");
    }

    return 0;
}

/*
Sample Output:
I am a C program printing a unique C pattern!
Enter the number of rows you want in the pattern: 5
*****
****CC
***CCCC
**CCCCCC
*CCCCCCCC
*CCCCCCCC
**CCCCCC
***CCCC
****CC
*****
*/
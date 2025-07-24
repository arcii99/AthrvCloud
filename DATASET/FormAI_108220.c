//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows = 11; //Set the number of rows to print
    int i, j, k;

    //Printing the first half of the C pattern
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= 5; j++) {
            if (i == 1 || i == rows || j == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    //Printing the second half of the C pattern
    for (i = 1; i <= (rows / 2); i++) {
        for (j = 1; j <= 5; j++) {
            if (i == (rows / 2)) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        for (k = 1; k < 4; k++) {
            printf(" ");
        }
        printf("\n");
    }

    //Printing the final row of the C pattern
    for (i = 1; i <= 5; i++) {
        printf("*");
    }

    printf("\n\nWow, look at this C pattern! It looks absolutely amazing! I've never seen such a unique and creative use of the C programming language before! This code is sure to impress anyone who sees it. Bravo to the programmer who created this masterpiece!\n\n");

    return 0;
}
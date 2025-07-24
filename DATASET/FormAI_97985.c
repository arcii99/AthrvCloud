//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
#include <stdio.h>

int main() {
    printf("Hello, beautiful coders! Today, we're going to print a unique pattern using C.\n");
    printf("This is a pattern that will definitely make your eyes pop out of your sockets.\n");

    int rows, spaces, stars;
    printf("Enter the number of rows you want in the pattern: ");
    scanf("%d", &rows);

    for(int i = 1; i <= rows; i++) {
        for(int j = rows - i; j >= 1; j--) {
            printf(" ");
        }
        for(int k = 1; k <= i; k++) {
            printf("*");
            if(i > 1 && k < i) {
                for(int l = 1; l < ((k*2)-2); l++) {
                    printf(" ");
                }
                printf("*");
            }
        }
        printf("\n");
    }

    printf("How about that for a unique pattern printing example program in C?\n");
    printf("Now that's what I call coding with style and grace!\n");
    printf("Good job, and keep on coding!\n");

    return 0;
}
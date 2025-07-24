//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

int main() {
    printf("Let's print a unique energy pattern!\n");

    int n = 8, i, j;

    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            if (i==1 || i==n || j==1 || j==n) {
                printf("*");
            }
            else if (i==j || i+j==n+1) {
                printf("o");
            }
            else if (i%2==0 && j%2==0) {
                printf("+");
            }
            else if (i%2==1 && j%2==1) {
                printf("-");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Enjoy the energy of the pattern!\n");
    return 0;
}
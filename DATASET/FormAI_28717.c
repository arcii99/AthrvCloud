//FormAI DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>

int main() {
    int i, j, k;

    // Upper portion of the C
    for(i=0; i<6; i++) {
        for(j=5; j>i; j--)
            printf(" ");
        for(k=0; k<=i; k++) {
            if(k==0 || i==5)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    // Lower portion of the C
    for(i=4; i>=0; i--) {
        for(j=5; j>i; j--)
            printf(" ");
        for(k=0; k<=i; k++) {
            if(k==0 || i==5)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
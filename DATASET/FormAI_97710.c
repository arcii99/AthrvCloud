//FormAI DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>

int main() {
    int h, w, i, j;

    printf("Enter height of C: ");
    scanf("%d", &h);

    if(h < 4) {
        printf("Height must be atleast 4.");
        return 0;
    }

    w = h / 2 + 1;

    for(i = 1; i <= h; i++) {
        if(i == 1) {
            for(j = 1; j <= w; j++) {
                printf("*");
            }
        }
        else if(i == h) {
            for(j = 1; j <= w; j++) {
                printf("*");
            }
        }
        else {
            printf("*");
        }

        if(i != 1 && i != h) {
            for(j = 2; j < w; j++) {
                printf(" ");
            }
        }

        if(i > 1 && i < h / 2 + 1) {
            printf("*");
        }
        else if (i > h / 2 + 1 && i < h) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
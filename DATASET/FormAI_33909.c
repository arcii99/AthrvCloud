//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
#include <stdio.h>

int main() {
    int i, j, k = 1;

    for(i = 0; i < 7; i++) {
        for(j = 0; j < 4; j++) {
            if((i < 2 && j < 2) || (i == 3 && j > 1) || (i > 3 && j > 1) || (i == 6 && j < 2)) {
                printf(" ");
            }
            else {
                printf("*");
            }
        }
        if(i == 3) {
            k = 0;
        }
        if(k) {
            printf("*\n");
        }
        else {
            printf(" *\n");
        }
    }

    return 0;
}
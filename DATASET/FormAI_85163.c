//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
#include <stdio.h>

int main() {

    printf("\n\n\n\t\t Thank You for Using This Program \t\t\n\n\n");

    printf("\t\t Here is your Grateful Pattern: \t\t\n\n");

    //Stars on top
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 17; j++) {
            printf("*");
        }
        printf("\n");
    }

    //Upper half of letters C
    for (int i = 0; i < 3; i++) {
        printf("*");
        for (int j = 0; j < 13; j++) {
            if (j == 0) {
                printf(" ");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }

    //Lower half of letters C
    for (int i = 0; i < 6; i++) {
        printf("*");
        if (i == 0 || i == 5) {
            for (int j = 0; j < 11; j++) {
                printf("*");
            }
        }
        else {
            printf("           *");
        }
        printf("\n");
    }

    //Stars on bottom
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 17; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n\n\n\t\t Thank You for Using This Program \t\t\n\n\n");

    return 0;
}
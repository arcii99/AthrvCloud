//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include<stdio.h>

int main() {

    int i, j;

    //Pattern 1
    for (i = 1; i <= 5; i++) {
        
        for (j = 1; j <= i; j++) {
        
            printf("*");
        }

        printf("\n");
    }

    //Pattern 2
    for (i = 1; i <= 5; i++) {
        
        for (j = 5; j >=i; j--) {
        
            printf("*");
        }

        printf("\n");
    }

    //Pattern 3
    for (i = 1; i <= 5; i++) {
        
        for (j = 1; j <= i; j++) {
        
            printf("%d",i);
        }

        printf("\n");
    }

    //Pattern 4
    for (i = 5; i >= 1; i--) {
        
        for (j = 1; j <= i; j++) {
        
            printf("%d",i);
        }

        printf("\n");
    }

    //Pattern 5
    for (i = 1; i <= 5; i++) {
        
        for (j = 1; j <= i; j++) {
        
            printf("%d ",j);
        }

        printf("\n");
    }

    //Pattern 6
    for (i = 5; i >= 1; i--) {
        
        for (j = 1; j <= i; j++) {
        
            printf("%d ",j);
        }

        printf("\n");
    }

    //Pattern 7
    for (i = 1; i <= 5; i++) {
        
        for (j = i; j >= 1; j--) {
        
            printf("*");
        }

        printf("\n");
    }

    //Pattern 8
    for (i = 5; i >= 1; i--) {
        
        for (j = 1; j <= i; j++) {
        
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
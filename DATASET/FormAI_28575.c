//FormAI DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>

int main(){

    int n = 5;
    int i, j, k;

    for (i = n; i >= 1; i--){
        for (j = i; j < n; j++)
            printf(" ");

        for (k = 1; k <= i; k++)
            printf("* ");
        
        printf("\n");
    }

    for (i = 1; i <= n; i++){
        for (j = i; j < n; j++)
            printf(" ");

        for (k = 1; k <= i; k++)
            printf("* ");
        
        printf("\n");
    }

    return 0;
}
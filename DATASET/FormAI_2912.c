//FormAI DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>
int main() {
    int rows, i, j, space;
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    for(i=0;i<=rows-1;i++) {
        for(space=0; space<=rows-i-2; space++)
            printf("  ");
            for(j=0; j<=i; j++)
                printf("* ");
                printf("\n");
    }
    for(i=rows-1;i>=0;i--) {
        for(space=0;space<=rows-i-2;space++)
            printf("  ");
            for(j=0;j<=i;j++)
                printf("* ");
                printf("\n");
    }
    return 0;
}
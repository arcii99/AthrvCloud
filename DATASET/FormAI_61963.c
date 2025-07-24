//FormAI DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>

int main() {
    int num, i, j, k;
    printf("Enter a number:\n");
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        for (j = 1; j < i; j++) {
            printf(" ");
        }
        for (k = 1; k <= num-i+1; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
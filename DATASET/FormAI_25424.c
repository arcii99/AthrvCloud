//FormAI DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>

int main() {
    int num, i, j;
    printf("Enter the number of rows you want in Floyds Triangle: ");
    scanf("%d", &num);
    int count = 1;
    for (i=1; i<=num; i++) {
        for (j=1; j<=i; j++) {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }
    return 0;
}
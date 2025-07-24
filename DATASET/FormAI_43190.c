//FormAI DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>

int main () {
    int size, i, j, num = 1;
    printf("Enter size of pattern : ");
    scanf("%d", &size);
    printf("\n");
    for (i = size; i >= 1; i--) {
        for (j = 1; j <= size; j++) {
            if (j == i) {
                printf("%d ", num % 10);
            }
            else {
                printf("%c ", i % 2 == 0 ? 'A' + (num % 26) : 'a' + (num % 26));
            }
            num++;
        }
        printf("\n");
    }
    printf("\n");
    num--;
    for (i = 2; i <= size; i++) {
        for (j = 1; j <= size; j++) {
            if (j == i) {
                printf("%d ", num % 10);
            }
            else {
                printf("%c ", j % 2 == 0 ? 'A' + (num % 26) : 'a' + (num % 26));
            }
            num--;
        }
        printf("\n");
    }
    return 0;
}
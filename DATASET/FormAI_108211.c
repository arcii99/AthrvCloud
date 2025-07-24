//FormAI DATASET v1.0 Category: Pattern printing ; Style: innovative
#include <stdio.h>

int main() {
    int num;
    printf("Enter the number of rows you want to print: ");
    scanf("%d", &num);

    int mid = num / 2;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i == 0 || i == num - 1 || j == i || j == num - i - 1 || j == mid) {
                printf("C");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
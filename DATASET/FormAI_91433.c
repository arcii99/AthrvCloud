//FormAI DATASET v1.0 Category: Pattern printing ; Style: Claude Shannon
#include<stdio.h>

int main() {
    int n = 5; // number of rows
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= 2*i-1; k++) {
            if (k == 1 || k == 2*i-1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = n-1; i >= 1; i--) {
        for (int j = n; j >= i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= 2*i-1; k++) {
            if (k == 1 || k == 2*i-1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
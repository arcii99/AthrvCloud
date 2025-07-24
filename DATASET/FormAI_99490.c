//FormAI DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of lines to print: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            printf(" ");
        }
        for(int k = 0; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < n-i-1; j++) {
            printf(" ");
        }
        for(int k = 0; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
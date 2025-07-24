//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {

    int size;
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        for (int j = size-i; j > 0; j--) {
            printf(" ");
        }
        printf("*");
        for (int k = 0; k < i*2; k++) {
            printf(" ");
            if (k == i*2-1) {
                printf("*");
            }
        }
        printf("\n");
    }
    
    for (int a = size-1; a >= 0; a--) {
        for (int b = size-a; b > 0; b--) {
            printf(" ");
        }
        printf("*");
        for (int c = 0; c < a*2; c++) {
            printf(" ");
            if (c == a*2-1) {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}
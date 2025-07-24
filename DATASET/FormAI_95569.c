//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cyberpunk
#include <stdio.h>

int main() {
    int i, j, k;
    int n = 21;
    int mid = n/2;
    for(i = 0; i < n; i++) {
        for(j = 0; j < mid; j++) {
            printf("=");
        }
        for(k = 0; k < i; k++) {
            printf("#");
        }
        printf("\\");
        for(j = mid + i + 1; j < n; j++) {
            printf("-");
        }
        printf("\n");
    }
    for(i = n-2; i >= 0; i--) {
        for(j = 0; j < mid; j++) {
            printf("=");
        }
        for(k = 0; k < i; k++) {
            printf("#");
        }
        printf("\\");
        for(j = mid + i + 1; j < n; j++) {
            printf("-");
        }
        printf("\n");
    }
    return 0;
}
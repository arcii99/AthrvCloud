//FormAI DATASET v1.0 Category: Pattern printing ; Style: systematic
#include<stdio.h>

void printPattern(int n) {
    int i, j, k;
    for(i = n; i >= 1; i--) {
        for(j = n; j >= i; j--) {
            printf("%2d", j);
        }
        for(k = i-1; k >= 1; k--) {
            printf("%2d", i);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPattern(n);
    return 0;
}
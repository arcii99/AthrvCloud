//FormAI DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n || ((i == n/2 || j == n/2) && (n % 2 == 1))) {
                printf("*");
            } else if(i == j) {
                printf("/");
            } else if(i == n - j + 1) {
                printf("\\");
            } else if(i < j && i < n - j + 1) {
                printf("^");
            } else if(i < j && i > n - j + 1) {
                printf("/");
            } else if(i > j && i > n - j + 1) {
                printf("v");
            } else if(i > j && i < n - j + 1) {
                printf("\\");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
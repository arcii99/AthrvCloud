//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include<stdio.h>

int main() {
    int n = 7;
    for(int i=n; i>=1; i--) {
        for(int j=1; j<=(2*n-1); j++) {
            if(j == i || j == (2*n-i)) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=(2*n-1); j++) {
            if(j == i || j == (2*n-i)) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
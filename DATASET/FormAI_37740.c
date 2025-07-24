//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int i, j, k, n=7;
    char symbol = '@';
    for(i=0;i<n;i++) {
        for(j=n;j>=0;j--) {
            if(j==i) {
                for(k=0;k<i;k++)
                    printf("%c",symbol);
            } else {
                printf(" ");
            }
        }
        for(j=0;j<i+1;j++) {
            if(j==0) {
                for(k=0;k<n-i-1;k++)
                    printf(" ");
                printf("%c", symbol);
            } else {
                printf("%c", symbol);
            }
        }
        printf("\n");
    }
    for(i=n-2;i>=0;i--) {
        for(j=n;j>=0;j--) {
            if(j==i) {
                for(k=0;k<i;k++)
                    printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        for(j=0;j<i+1;j++) {
            if(j==0) {
                for(k=0;k<n-i-1;k++)
                    printf(" ");
                printf("%c", symbol);
            } else {
                printf("%c", symbol);
            }
        }
        printf("\n");
    }
    return 0;
}
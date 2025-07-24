//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include<stdio.h>
void printFirstHalf(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            printf("*");
        }
        for(int j=1; j<=(i-1)*2; j++) {
            printf(" ");
        }
        for(int j=i; j<=n; j++) {
            printf("*");
        }
        printf("\n");
    }    
}

void printSecondHalf(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            printf("*");
        }
        for(int j=(n-i)*2; j>=1; j--) {
            printf(" ");
        }
        for(int j=1; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printC(int n) {
    printFirstHalf(n);
    printSecondHalf(n/2+1);
}

int main() {
    int n;
    printf("Enter the height of the C pattern: ");
    scanf("%d", &n);
    printC(n);
    return 0;
}
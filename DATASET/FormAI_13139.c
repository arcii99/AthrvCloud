//FormAI DATASET v1.0 Category: Educational ; Style: optimized
#include<stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The first %d even numbers are: ", n);
    for(int i = 0; i < n; i++) {
        printf("%d ", 2*i);
    }
    printf("\nThe first %d odd numbers are: ", n);
    for(int i = 0; i < n; i++) {
        printf("%d ", 2*i+1);
    }
    printf("\n\nMultiplication Table of %d:\n", n);
    for(int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n*i);
    }
    printf("\nFibonacci Sequence upto %d terms:\n", n);
    int a = 0, b = 1, c;
    printf("%d ", a);
    if(n > 1) {
        printf("%d ", b);
    }
    for(int i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n\nPrime numbers upto %d are: ", n);
    for(int i = 2; i <= n; i++) {
        int flag = 1;
        for(int j = 2; j*j <= i; j++) {
            if(i % j == 0) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include<stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The prime numbers between 1 and %d are:\n", n);
    for(int i=2; i<=n; i++) {
        int flag = 1;
        for(int j=2; j*j<=i; j++) {
            if(i%j == 0) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
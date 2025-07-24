//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include <stdio.h>

int isPrime(int n) {
    int i;
    for(i=2; i*i<=n; i++) {
        if(n%i==0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Prime numbers between 2 and %d are:\n",n);
    for(i=2; i<=n; i++) {
        if(isPrime(i)==1) {
            printf("%d\n",i);
        }
    }
    return 0;
}
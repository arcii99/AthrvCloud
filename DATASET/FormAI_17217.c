//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include<stdio.h>

int isPrime(int n) {
    if(n<=1) return 0; //not prime
    if(n==2 || n==3) return 1; //prime
    if(n%2==0 || n%3==0) return 0; //not prime
    int i=5,w=2; 
    while(i*i <= n) {
        if(n%i==0) return 0; //not prime
        i+=w;
        w=6-w;
    }
    return 1; //prime
}

int main() {
    int n;
    printf("Enter a number to generate prime numbers up to that number: ");
    scanf("%d",&n);
    printf("Prime numbers up to %d are:\n",n);
    for(int i=2;i<=n;i++) {
        if(isPrime(i)) printf("%d ",i);
    }
    printf("\n");
    return 0;
}
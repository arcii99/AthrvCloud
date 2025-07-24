//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>
#include <math.h>

int is_prime(int n) {
    if(n<=1) return 0;
    if(n<=3) return 1;
    if(n%2==0 || n%3==0) return 0;
    for(int i=5; i*i<=n; i+=6) {
        if(n%i==0 || n%(i+2)==0)
            return 0;
    }
    return 1;
}

int main() {
    int n, i=2, flag=0;
    printf("Enter the number of prime numbers to be generated: ");
    scanf("%d",&n);
    if(n>=1) {
        printf("First %d prime numbers:\n",n);
        printf("%d ",i);
    }
    for(int count=2; count<=n; i++) {
        if(is_prime(i)) {
            printf("%d ",i);
            count++;
        }
    }  
    return 0;
}
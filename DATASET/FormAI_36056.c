//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include <stdio.h>

int isPrime(int n){
    int i;
    for(i=2;i<=n/2;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int n,i;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    printf("Prime numbers less than %d: ",n);
    for(i=2;i<=n;i++){
        if(isPrime(i)){
            printf("%d ",i);
        }
    }
    return 0;
}
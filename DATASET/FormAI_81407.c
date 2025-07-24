//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n){
    if(n<=1)
        return false;
    for(int i=2;i<=n/2;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    int limit;
    printf("Enter the limit: ");
    scanf("%d",&limit);
    printf("The prime numbers are: ");
    int count = 0;
    for(int i=1;i<=limit;i++){
        if(isPrime(i)){
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal number of prime numbers: %d", count);
    return 0;
}
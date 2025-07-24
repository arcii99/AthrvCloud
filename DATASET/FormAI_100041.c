//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n){
    if(n<=1)
        return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    int limit;
    printf("Enter the limit for prime number generation: ");
    scanf("%d",&limit);
    printf("Prime numbers from 2 to %d: ",limit);
    for(int i=2;i<=limit;i++){
        if(is_prime(i))
            printf("%d ",i);
    }
    return 0;
}
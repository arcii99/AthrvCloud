//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: scalable
#include<stdio.h>
#include<stdbool.h>

bool checkPrime(int num){
    int i;
    for(i=2;i<=num/2;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n, i=2, count=0;
    printf("Enter the number of primes to generate: ");
    scanf("%d",&n);
    printf("The first %d prime numbers are: \n",n);

    while(count<n){
        if(checkPrime(i)){
            printf("%d ",i);
            count++;
        }
        i++;
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include<stdio.h>

int isPrime(int num){
    int i;
    if(num==2)
        return 1;
    if(num%2==0)
        return 0;
    for(i=3;i*i<=num;i+=2){
        if(num%i==0)
            return 0;
    }
    return 1;
}

void generatePrimes(int n){
    int i,count=0;
    for(i=2;;i++){
        if(isPrime(i)==1){
            printf("%d ",i);
            count++;
        }
        if(count==n)
            break;
    }
}

int main(){
    int n;
    printf("Enter the number of primes you want to generate: ");
    scanf("%d",&n);
    printf("The first %d prime numbers are: ",n);
    generatePrimes(n);
    return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h>

int isPrime(int num){
    if(num <= 1){
        return 0;
    }
    for(int i=2;i<num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

void generatePrimes(int n){
    printf("List of Prime Numbers:\n");
    for(int num=2;num<=n;num++){
        if(isPrime(num)){
            printf("%d ",num);
        }
    }
}

int main(){
    int limit;
    printf("Enter the maximum number: ");
    scanf("%d",&limit);
    generatePrimes(limit);
    return 0;
}
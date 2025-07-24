//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include<stdio.h>

int isPrime(int number){
    int i, flag=1;
    if(number==1) return 0;
    for(i=2; i<=number/2; ++i){
        if(number%i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    int n, i, count, limit;
    printf("Enter the number of prime numbers you wish to generate: ");
    scanf("%d", &n);
    printf("\n");
    printf("The first %d Prime numbers are:\n", n);
    printf("2 ");
    count = 1;
    limit = 100000;
    for(i=3; count<n; i++){
        if(isPrime(i) == 1){
            printf("%d ", i);
            count++;
        }
        if(i>limit){
            printf("\nReached limit\n");
            break;
        }
    }
    return 0;
}
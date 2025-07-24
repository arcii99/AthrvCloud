//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include <stdio.h>

void printPrimes(int n){
    int i,j,ctr;
    printf("The first %d prime numbers are: ", n);
    for(i=2; ;i++){
        ctr=0;
        for(j=2;j<i;j++){
            if(i%j==0){
                ctr++;
                break;
            }
        }
        if(ctr==0){
            printf("%d ",i);
            n--;
        }
        if(n<=0){
            break;
        }
    }
}

int main(){
    int n;
    printf("Please enter the number of primes you want to generate: ");
    scanf("%d",&n);
    printPrimes(n);

    return 0;
}
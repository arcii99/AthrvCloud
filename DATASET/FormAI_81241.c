//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>

int isPrime(int n){
    if(n<2){
        return 0;
    }
    int i;
    for(i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void primeGenerator(int n){
    int counter=0;
    int i;
    for(i=2;counter<n;i++){
        if(isPrime(i)){
            counter++;
            printf("%d ",i);
        }
    }
    printf("\n");
}

int main(){
    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter the number of prime numbers you want to generate: ");
    int n;
    scanf("%d",&n);
    printf("The first %d prime numbers are: ",n);
    primeGenerator(n);
    printf("Thank you for using the Prime Number Generator!\n");
    return 0;
}
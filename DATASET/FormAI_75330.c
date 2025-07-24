//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num){
    if(num <= 1){
        return false;
    }
    for(int i=2; i*i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void generatePrime(int start, int end){
    printf("The prime numbers between %d and %d are:\n", start, end);
    for(int i=start; i<=end; i++){
        if(isPrime(i)){
            printf("%d\n", i);
        }
    }
}

int main(){
    int start, end;
    printf("Enter the starting and ending numbers: ");
    scanf("%d%d", &start, &end);
    generatePrime(start, end);
    return 0;
}
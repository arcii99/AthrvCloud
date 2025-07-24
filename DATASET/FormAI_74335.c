//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num){
    if(num <= 1){
        return false;
    }
    else{
        int i;
        for(i = 2; i <= num / 2; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}

int main(){
    int n, i;
    printf("Enter the number of prime numbers needed: ");
    scanf("%d", &n);
    printf("Generating the first %d prime numbers:\n", n);

    int count = 0;
    i = 2;
    while(count < n){
        if(isPrime(i)){
            count++;
            printf("%d ", i);
        }
        i++;
    }
    printf("\n");
    return 0;
}
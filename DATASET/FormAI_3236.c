//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n){
    if(n <= 1){
        return false;
    }
    for(int i=2; i<=n/2; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 2, count = 0;
    printf("Generating prime numbers:\n\n");
    while(count != 50){
        if(isPrime(n)){
            printf("%d ", n);
            count++;
        }
        n++;
    }
    printf("\n\nDone!");
    return 0;
}
//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: random
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num){
    if (num <= 1)
        return false;
    for(int i=2;i<num;i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

void print_primes(int num){
    for(int i=2;i<=num;i++){
        if (is_prime(i)){
            printf("%d\n",i);
        }
    }
}

int main(){
    int n = 100000;
    print_primes(n);
    return 0;
}
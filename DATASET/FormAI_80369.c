//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: realistic
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num){
    if(num <= 1) return false;
    for(int i = 2; i*i <= num; i++){
        if(num%i == 0) return false;
    }
    return true;
}

void generate_primes(int max){
    for(int num = 2; num <= max; num++){
        if(is_prime(num)){
            printf("%d ", num);
        }
    }
}

int main(){
    int max;
    printf("Enter the maximum number: ");
    scanf("%d", &max);
    printf("Generated prime numbers up to %d are: ", max);
    generate_primes(max);
    printf("\n");
    return 0;
}
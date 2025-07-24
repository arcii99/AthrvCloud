//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Sherlock Holmes
#include<stdio.h>

int is_prime(int num){
    int i;
    if (num == 2 || num == 3)
        return 1;
    if (num == 1 || num % 2 == 0)
        return 0;
    for(i = 3; i < num / 2; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void generate_primes(int n){
    int i, j, count = 0;
    printf("The first %d prime numbers are: ", n);
    for(i = 2; count < n; i++){
        if(is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
}

int main(){
    int n;
    printf("How many prime numbers do you want to generate? ");
    scanf("%d", &n);
    generate_primes(n);
    return 0;
}
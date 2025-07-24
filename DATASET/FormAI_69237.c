//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>

int is_prime(int num) { // function to check if number is prime or not
    if(num < 2) {
        return 0;
    }
    for(int i=2; i<num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, count = 0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);

    printf("The first %d prime numbers are:\n", num);

    for(int i=2; count<num; i++) {
        if(is_prime(i)) { // check if the number is prime
            printf("%d ", i);
            count++;
        }
    }

    return 0;
}
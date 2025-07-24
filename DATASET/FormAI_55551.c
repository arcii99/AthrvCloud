//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <time.h>

int main() {

    clock_t t;
    double time_taken;

    t = clock();
    // Begin execution of Benchmark program
    int sum = 0;
    for (int i = 1; i <= 1000000; i++) {
        sum += i;
    }
    printf("Sum of numbers from 1 to 1,000,000 is: %d\n", sum);

    int max_num_primes = 5000; // Max number of prime numbers
    int prime_numbers[max_num_primes];
    int is_prime = 1;
    
    prime_numbers[0] = 2; // Initializing with first prime number
    int count = 1;
    
    for (int i = 3; count < max_num_primes; i += 2) {
        is_prime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime == 1) {
            prime_numbers[count++] = i;
        }
    }
    printf("First %d prime numbers are: ", max_num_primes);
    for (int i = 0; i < max_num_primes; i++) {
        printf("%d ", prime_numbers[i]);
    }
    printf("\n");

    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // Calculate execution time
    printf("Benchmark program executed in %f seconds\n", time_taken);

    return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: relaxed
#include <stdio.h>

int main() {
    int primes[10001]; // assume we want up to the 10000th prime
    int count = 0; // count of prime numbers found so far
    primes[count++] = 2; // 2 is the first prime
    
    int num = 3; // start checking at 3
    while (count < 10001) { // keep checking until we have 10001 primes
        int is_prime = 1; // assume the number is prime unless proven otherwise
        
        // check if num is divisible by any prime less than num
        for (int i = 0; i < count; i++) {
            if (num % primes[i] == 0) {
                is_prime = 0; // num is not prime if divisible by any prime less than num
                break;
            }
        }
        
        if (is_prime) {
            primes[count++] = num; // add this prime to the list
        }
        
        num += 2; // check next odd number
    }
    
    // print out the 10000th prime number
    printf("The 10000th prime number is: %d", primes[10000]);
    
    return 0;
}
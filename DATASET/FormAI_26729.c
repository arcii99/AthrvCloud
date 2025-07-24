//FormAI DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>

/* This program generates a random number and then tests whether
 * it is prime. If it is prime, the program will output "YES".
 * Otherwise, it will output "NO".
 */

/* Function to generate a random number between 1 and 100 */
int rand_num() {
    int num = rand() % 100 + 1;
    return num;
}

/* Function to test if a number is prime */
int is_prime(int num) {
    int i;
    for(i = 2; i < num; i++) {
        if(num % i == 0) {
            /* If the number is divisible by anything other than
             * 1 or itself, it is not prime.
             */
            return 0;
        }
    }
    /* If we make it through the loop without finding any factors,
     * the number is prime.
     */
    return 1;
}

int main() {
    int num = rand_num();
    printf("The random number is: %d\n", num);
    if(is_prime(num)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
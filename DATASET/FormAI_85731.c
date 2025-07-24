//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

/* Function to check if a number is prime */
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/* Function to print prime numbers asynchronously */
void *print_primes(void *args) {
    int *n = (int *) args;
    for (int i = 2; i <= *n; ++i) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
        usleep(100000); // Wait for 0.1 seconds before printing the next prime number
    }
    printf("Done!\n");
    pthread_exit(NULL);
}

int main() {
    int n;
    pthread_t thread_id;

    printf("Enter the number till which you want to generate prime numbers: ");
    scanf("%d", &n);

    if (pthread_create(&thread_id, NULL, print_primes, &n)) {
        fprintf(stderr, "Error creating thread\n");
        return EXIT_FAILURE;
    }

    pthread_join(thread_id, NULL);
    return EXIT_SUCCESS;
}
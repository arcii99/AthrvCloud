//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

int prime_count = 0; // Counter for the number of prime numbers generated
pthread_mutex_t mutex_factor; // Mutex to lock computation of factors
pthread_mutex_t mutex_output; // Mutex to lock output of prime integers

void *gen_prime(void *thread_id);

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    int i;
    
    pthread_mutex_init(&mutex_factor, NULL);
    pthread_mutex_init(&mutex_output, NULL);
    
    for(i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, gen_prime, (void *) &thread_ids[i]);
    }
    
    for(i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex_factor);
    pthread_mutex_destroy(&mutex_output);
    
    printf("Total primes generated: %d\n", prime_count);
    
    return 0;
}

void *gen_prime(void *thread_id) {
    int id = *(int *) thread_id;
    int num = id;
    int i;
    bool is_prime;
    
    while(true) {
        is_prime = true;
        pthread_mutex_lock(&mutex_factor);
        num++;
        pthread_mutex_unlock(&mutex_factor);
        
        for(i = 2; i < num; i++) {
            if(num % i == 0) {
                is_prime = false;
                break;
            }
        }
        
        if(is_prime) {
            pthread_mutex_lock(&mutex_output);
            printf("Thread %d generated prime number: %d\n", id, num);
            prime_count++;
            pthread_mutex_unlock(&mutex_output);
        }
    }
    
    pthread_exit(NULL);
}
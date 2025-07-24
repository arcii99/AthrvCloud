//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

#define NUM_THREADS 4

pthread_mutex_t lock;

int circuit[NUM_THREADS][4] = {
    {1,0,0,1},  /* Circuit 0 */
    {0,1,1,0},  /* Circuit 1 */
    {1,1,0,0},  /* Circuit 2 */
    {0,0,1,1}   /* Circuit 3 */
};

int input_array[NUM_THREADS][2] = {
    {0,1},
    {1,0},
    {1,1},
    {0,0}
};

typedef struct {
    int thread_index;
} thread_params;

void *simulate_circuit(void *parameters) {
    thread_params *params = (thread_params *) parameters;
    int thread_index = params -> thread_index;
    int gate_a, gate_b, output;
    int input_a = input_array[thread_index][0];
    int input_b = input_array[thread_index][1];
    printf("Simulating circuit %d with input A = %d and input B = %d\n", thread_index, input_a, input_b);

    pthread_mutex_lock(&lock);
    gate_a = circuit[thread_index][0] * input_a + circuit[thread_index][1] * input_b;
    gate_b = circuit[thread_index][2] * input_a + circuit[thread_index][3] * input_b;
    output = gate_a * gate_b;
    printf("Output of circuit %d is %d\n", thread_index, output);
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_params thread_arguments[NUM_THREADS];
    int i;

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < NUM_THREADS; i++) {
        thread_arguments[i].thread_index = i;
        pthread_create(&threads[i], NULL, simulate_circuit, &thread_arguments[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}
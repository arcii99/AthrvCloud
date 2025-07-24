//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Public key algorithm implementation
int public_key_algorithm(int a, int b)
{
    int result = a; 
    for (int i = 1; i < b; i++) {
        result = (result * a) % b;
    }
    return result;
}

// Thread function to execute public key algorithm
void *threadFunction(void *args)
{
    int *input = (int*) args;

    // Compute public key algorithm
    int result = public_key_algorithm(input[0], input[1]);

    // Print the result
    printf("Result of public key algorithm for %d and %d is %d\n", input[0], input[1], result);

    pthread_exit(NULL);
}

int main() {
    // Initialize input arguments for public key algorithm
    int input1[2] = {2, 13};
    int input2[2] = {3, 11};
    int input3[2] = {5, 17};
    int input4[2] = {7, 19};

    // Create threads to execute public key algorithm for each input
    pthread_t threads[4];
    pthread_create(&threads[0], NULL, threadFunction, (void*)input1);
    pthread_create(&threads[1], NULL, threadFunction, (void*)input2);
    pthread_create(&threads[2], NULL, threadFunction, (void*)input3);
    pthread_create(&threads[3], NULL, threadFunction, (void*)input4);

    // Wait for all threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
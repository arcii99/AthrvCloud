//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

double elementA = 10.0; // Initial quantity of Element A
double elementB = 20.0; // Initial quantity of Element B
double reactionRate = 0.5; // Rate of reaction

// Function to perform the chemical reaction between Element A and Element B
void* chemical_reaction(void* thread_id) {
    int id = (int) thread_id;
    double reactionTime = 0.1; // Reaction time
    while(1) {
        if(id == 0) {
            double reaction = reactionRate * elementA * elementB;
            elementA = elementA - (reaction * reactionTime);
            elementB = elementB - (reaction * reactionTime);
            printf("Thread %d: Element A = %f, Element B = %f\n", id, elementA, elementB);
        }
        else {
            double reaction = reactionRate * elementA * elementB;
            elementA = elementA + (reaction * reactionTime);
            elementB = elementB + (reaction * reactionTime);
            printf("Thread %d: Element A = %f, Element B = %f\n", id, elementA, elementB);
        }
        sleep(1); // Wait for 1 second
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

    // Create threads for chemical reaction simulation
    for(int i = 0; i < NUM_THREADS; i++) {
        printf("Main thread: Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, chemical_reaction, (void *)i);
        if(rc) {
            printf("Error: Unable to create thread %d with code %d\n", i, rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Exit program
    pthread_exit(NULL);
}
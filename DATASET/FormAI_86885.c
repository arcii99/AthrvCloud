//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROPHESIES 5

char *prophesies[MAX_PROPHESIES] = {
    "You will have good luck today!",
    "Your hard work will pay off soon.",
    "You will meet someone new today.",
    "An opportunity will present itself in the near future.",
    "You will find something you have been looking for."
};

pthread_mutex_t mutex_lock; // mutex lock used to protect critical section
int current_prophesy = -1; // initial value to indicate no prophesy generated yet

void *generate_prophesy(void *thread_id) {
    srand((int)time(NULL)); // seed the random number generator
    pthread_mutex_lock(&mutex_lock); // acquire the lock
    current_prophesy = rand() % MAX_PROPHESIES; // generate a random index for the prophesies array
    pthread_mutex_unlock(&mutex_lock); // release the lock
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3]; // declare an array of threads
    int i;
    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, generate_prophesy, (void *)i); // create 3 threads and pass their IDs as arguments
    }
    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL); // wait for all threads to finish
    }
    printf("The fortune teller predicts: %s\n", prophesies[current_prophesy]); // print the generated prophesy
    return 0;
}
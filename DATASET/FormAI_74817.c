//FormAI DATASET v1.0 Category: Random ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_RANDOM 10

void *generate_random_numbers(void *thread_id) {
    int id = *(int*)thread_id;
    int i, random_num;
    char filename[20];
    FILE *fp;

    sprintf(filename, "random_nums_%d.txt", id);
    fp = fopen(filename, "w");

    for(i = 0; i < MAX_RANDOM; i++) {
        random_num = rand() % 100;
        fprintf(fp, "%d\n", random_num);
        usleep(100); // Sleep for some time to allow other threads to run
    }

    fclose(fp);
    pthread_exit(NULL);
}

int main() {
    int i, rc;
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    srand(time(NULL)); // Seed for random number generation

    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, generate_random_numbers, (void *)&thread_ids[i]);

        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Join all threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);

        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    printf("Random number generation completed by all threads.\n");

    pthread_exit(NULL);
}
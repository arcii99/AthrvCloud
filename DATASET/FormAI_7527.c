//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LEN 100
#define MAX_GENOME_LEN 1000000

char genome[MAX_GENOME_LEN];
int genome_len = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int cur_thread_id = 0;
int thread_completed[MAX_THREADS] = {0};

void* gen_random_substr(void* arg) {
    int thread_id = *(int*)arg;
    char substr[MAX_STRING_LEN];
    int i, j, len;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (thread_completed[thread_id] || cur_thread_id != thread_id) {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
        len = rand() % MAX_STRING_LEN + 1;
        for (i = 0; i < len; i++) {
            substr[i] = 'A' + rand() % 4;
        }
        substr[len] = '\0';
        int found = 0;
        for (i = 0; i <= genome_len - len; i++) {
            if (strncmp(&genome[i], substr, len) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("Thread %d found a match: %s\n", thread_id, substr);
        }
        else {
            printf("Thread %d did not find any matches.\n", thread_id);
        }
        pthread_mutex_lock(&mutex);
        thread_completed[thread_id] = 1;
        cur_thread_id = (cur_thread_id + 1) % MAX_THREADS;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main(void) {
    int i, thread_id[MAX_THREADS];
    pthread_t threads[MAX_THREADS];
    srand(time(NULL));
    printf("Generating genome...\n");
    for (i = 0; i < MAX_GENOME_LEN; i++) {
        genome[i] = 'A' + rand() % 4;
    }
    genome[MAX_GENOME_LEN] = '\0';
    genome_len = strlen(genome);
    printf("Genome generated with length %d.\n", genome_len);
    for (i = 0; i < MAX_THREADS; i++) {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, gen_random_substr, &thread_id[i]);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;
int fortunes[8][2] = {{0,4},{1,3},{2,0},{4,2},{3,1},{2,4},{1,2},{0,3}};

void *fortune_teller(void *thread_id) {
    int tid = *(int*)thread_id;
    srand(time(NULL) * tid);
    int random_index = rand() % 8;
    int fortune_number = fortunes[random_index][tid % 2];
    char *fortunes[] = {"You will meet a tall, dark stranger.", 
                        "Your future looks bright!", 
                        "Beware of unexpected danger!", 
                        "You will find happiness in unexpected places.", 
                        "A change is coming in your life.",
                        "You will be successful in your next venture.",
                        "Trust your instincts, they will guide you well.",
                        "Love is on the horizon."};
    char *fortune = fortunes[fortune_number];
    pthread_mutex_lock(&mutex);
    printf("Thread %d's fortune is: %s\n", tid, fortune);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    int ids[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, fortune_teller, (void*)&ids[i]);
    }
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
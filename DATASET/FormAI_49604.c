//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_DISKS 10
#define NUM_THREADS 3

int tower[3][NUM_DISKS];
int top[3] = {NUM_DISKS - 1, -1, -1};
int moves[NUM_DISKS];
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond[NUM_THREADS];

void* move_disks(void* arg);

int main() {
    // Initialize the tower of Hanoi
    for (int i = 0; i < NUM_DISKS; i++) {
        tower[0][i] = NUM_DISKS - i;
    }
    
    pthread_t threads[NUM_THREADS];
    
    // Initialize condition variables for each thread
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_cond_init(&cond[i], NULL);
    }
    
    // Create threads
    int ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, move_disks, (void*) &ids[i]);
    }
    
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print out the moves
    for (int i = 0; i < NUM_DISKS; i++) {
        printf("Move %d: Disk %d from Tower %d to Tower %d\n", i+1, moves[i], (moves[i]-1)%3+1, (moves[i]+1)%3+1);
    }
    
    return 0;
}

void* move_disks(void* arg) {
    int id = *(int*) arg;
    int from, to, disk;
    
    while (count < NUM_DISKS) {
        // Determine which towers this thread will work on
        if (id == 0) {
            from = 0; to = 1;
        } else if (id == 1) {
            from = 1; to = 2;
        } else {
            from = 2; to = 0;
        }
        
        pthread_mutex_lock(&mutex);
        while (top[from] == -1 || (top[to] != -1 && tower[from][top[from]] > tower[to][top[to]])) {
            pthread_cond_wait(&cond[id], &mutex);
        }
        disk = tower[from][top[from]--];
        tower[to][++top[to]] = disk;
        moves[count++] = disk;
        pthread_cond_signal(&cond[(id+1)%NUM_THREADS]);
        pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}
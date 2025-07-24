//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TOTAL_KNIGHTS 10

pthread_mutex_t sword_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t sword_available_cond = PTHREAD_COND_INITIALIZER;

int sword_available = 0;
int knights_with_sword = 0;

void *knights(void *arg) {
    int id = *(int *) arg;
    printf("Knight %d has arrived in Camelot!\n", id);
    
    pthread_mutex_lock(&sword_mutex);
    
    while (!sword_available) {
        printf("Knight %d is waiting for the sword to become available...\n", id);
        pthread_cond_wait(&sword_available_cond, &sword_mutex);
    }
    
    sword_available = 0;
    knights_with_sword++;
    printf("Knight %d has picked up the sword! The sword is now wielded by %d knights.\n", id, knights_with_sword);
    pthread_mutex_unlock(&sword_mutex);
    
    sleep(1); // knight performs actions with sword
    
    pthread_mutex_lock(&sword_mutex);
    knights_with_sword--;
    printf("Knight %d has returned the sword. %d knights are now wielding the sword.\n", id, knights_with_sword);
    if (knights_with_sword == 0) {
        sword_available = 1;
        printf("The sword is now available for another knight!\n");
        pthread_cond_signal(&sword_available_cond);
    }
    pthread_mutex_unlock(&sword_mutex);
}

int main() {
    pthread_t knight_threads[TOTAL_KNIGHTS];
    int ids[TOTAL_KNIGHTS];
    
    for (int i = 0; i < TOTAL_KNIGHTS; i++) {
        ids[i] = i + 1;
        pthread_create(&knight_threads[i], NULL, knights, &ids[i]);
    }
    
    for (int i = 0; i < TOTAL_KNIGHTS; i++) {
        pthread_join(knight_threads[i], NULL);
    }
    
    return 0;
}
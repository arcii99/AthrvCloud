//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: medieval
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t knights[4];
pthread_mutex_t mutex;

void* battle(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("%s has entered the battle.\n", (char*)arg);
    printf("%s is fighting the enemy...\n", (char*)arg);
    sleep(3);
    printf("%s has defeated the enemy!\n", (char*)arg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* feast(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("%s has arrived at the feast.\n", (char*)arg);
    printf("%s is enjoying the food and drink...\n", (char*)arg);
    sleep(2);
    printf("%s has finished the feast!\n", (char*)arg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    int i;

    pthread_mutex_init(&mutex, NULL);

    char* knight_names[4] = {"Sir Lancelot", "Sir Galahad", "Sir Robin", "Sir Bedevere"};

    for (i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            pthread_create(&knights[i], NULL, battle, (void*)knight_names[i]);
        } else {
            pthread_create(&knights[i], NULL, feast, (void*)knight_names[i]);
        }
    }

    for (i = 0; i < 4; i++) {
        pthread_join(knights[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
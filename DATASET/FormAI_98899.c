//FormAI DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

int x, y;

void* move_up(){
    pthread_mutex_lock(&lock);
    y += 1;
    printf("Moved Up\nCurrent position: (%d,%d)\n", x, y);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* move_down(){
    pthread_mutex_lock(&lock);
    y -= 1;
    printf("Moved Down\nCurrent position: (%d,%d)\n", x, y);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* move_left(){
    pthread_mutex_lock(&lock);
    x -= 1;
    printf("Moved Left\nCurrent position: (%d,%d)\n", x, y);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* move_right(){
    pthread_mutex_lock(&lock);
    x += 1;
    printf("Moved Right\nCurrent position: (%d,%d)\n", x, y);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    x=0;
    y=0;
    pthread_t tid1, tid2, tid3, tid4;
    pthread_mutex_init(&lock, NULL);

    printf("Starting position: (%d,%d)\n", x, y);

    pthread_create(&tid1, NULL, move_up, NULL);
    pthread_create(&tid2, NULL, move_left, NULL);
    pthread_create(&tid3, NULL, move_down, NULL);
    pthread_create(&tid4, NULL, move_right, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}
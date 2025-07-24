//FormAI DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int posX = 0;
int posY = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* moveRobot(void* arg) {
    int* moves = (int*) arg;
    for(int i = 0; moves[i] != -1; i++) {
        pthread_mutex_lock(&mutex);
        if(moves[i] == 1) {
            posY++;
        } else if(moves[i] == 2) {
            posX++;
        } else if(moves[i] == 3) {
            posY--;
        } else if(moves[i] == 4) {
            posX--;
        }
        printf("Robot moved to position: (%d, %d)\n", posX, posY);
        pthread_mutex_unlock(&mutex);
        usleep(500000);
    }
    pthread_exit(NULL);
}

int main() {
    int moves[] = {1,2,3,4,1,1,2,2,3,3,4,4,-1};
    pthread_t tid;
    pthread_create(&tid, NULL, moveRobot, (void*) moves);
    pthread_join(tid, NULL);
    return 0;
}
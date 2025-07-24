//FormAI DATASET v1.0 Category: Scientific ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1; //semaphore to control access to buffer1
sem_t sem2; //semaphore to control access to buffer2

int buffer1[10]; // buffer1
int buffer2[10]; // buffer2

void *thread1(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        sem_wait(&sem1); //wait for access to buffer1
        buffer1[i] = i * 2; //add item to buffer1
        printf("Thread1: added %d to buffer1\n", buffer1[i]);
        sem_post(&sem2); //signal access to buffer2
    }
    pthread_exit(NULL);
}

void *thread2(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        sem_wait(&sem2); //wait for access to buffer2
        buffer2[i] = buffer1[i]*3; //multiply item in buffer1 by 3 and add to buffer2
        printf("Thread2: added %d to buffer2\n", buffer2[i]);
        sem_post(&sem1); //signal access to buffer1
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2;

    sem_init(&sem1, 0, 1); //initialize sem1 with value 1 to allow access to buffer 1
    sem_init(&sem2, 0, 0); //initialize sem2 with value 0 to block access to buffer 2

    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);

    return 0;
}
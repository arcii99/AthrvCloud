//FormAI DATASET v1.0 Category: Queue ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX 5

typedef struct queue {
    int items[MAX];
    int front;
    int rear;
} queue;

queue Q;

pthread_mutex_t mutex;

void initializeQueue() {
    Q.front = -1;
    Q.rear = -1;
}

int isFull() {
    if ((Q.front == Q.rear + 1) || (Q.front == 0 && Q.rear == MAX - 1)) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (Q.front == -1) {
        return 1;
    }
    return 0;
}

void insertQueue(int element) {
    if (isFull()) {
        printf("\n Queue is full!! \n");
    } else {
        if (Q.front == -1) {
            Q.front = 0;
        }
        Q.rear = (Q.rear + 1) % MAX;
        Q.items[Q.rear] = element;
        printf("\n Inserted -> %d", element);
    }
}

int deleteQueue() {
    int element;
    if (isEmpty()) {
        printf("\n Queue is empty !! \n");
        return (-1);
    } else {
        element = Q.items[Q.front];
        if (Q.front == Q.rear) {
            Q.front = -1;
            Q.rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it.  */
        else {
            Q.front = (Q.front + 1) % MAX;
        }
        printf("\n Deleted element -> %d \n", element);
        return element;
    }
}

void* thread1() {
    int num;
    for (int i = 0; i < 5; i++) {
        num = rand() % 10;
        pthread_mutex_lock(&mutex);
        insertQueue(num);
        pthread_mutex_unlock(&mutex);
    }
}

void* thread2() {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);
        deleteQueue();
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    initializeQueue();
    pthread_t tid[2];

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid[0], NULL, thread1, NULL);
    pthread_create(&tid[1], NULL, thread2, NULL);

    for (int i = 0; i < 2; i++) {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
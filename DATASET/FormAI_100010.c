//FormAI DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SIZE 10

int array[MAX_SIZE];
int index = 0;

pthread_mutex_t lock;

void printArray() {
    printf("[ ");
    for(int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void insert(int num) {
    pthread_mutex_lock(&lock);
    if(index < MAX_SIZE) {
        array[index] = num;
        index++;
        printf("Inserting %d into array...\n", num);
        printArray();
    } else {
        printf("Array is full, cannot insert %d!\n", num);
    }
    pthread_mutex_unlock(&lock);
}

void delete(int num) {
    pthread_mutex_lock(&lock);
    int found = 0;
    for(int i = 0; i < MAX_SIZE; i++) {
        if(array[i] == num) {
            array[i] = 0;
            found = 1;
            printf("Deleting %d from array...\n", num);
            printArray();
            break;
        }
    }
    if(!found) {
        printf("%d not found in array, cannot delete!\n", num);
    }
    pthread_mutex_unlock(&lock);
}

void *insertAsync(void *arg) {
    int *num = (int*)arg;
    insert(*num);
    free(num);
    return NULL;
}

void *deleteAsync(void *arg) {
    int *num = (int*)arg;
    delete(*num);
    free(num);
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_mutex_init(&lock, NULL);
    pthread_t threads[20];
    for(int i = 0; i < 10; i++) {
        int *num = malloc(sizeof(int));
        *num = rand() % 100;
        pthread_create(&threads[i], NULL, insertAsync, (void*)num);
        usleep(500000);
    }
    for(int i = 10; i < 20; i++) {
        int *num = malloc(sizeof(int));
        *num = rand() % 100;
        pthread_create(&threads[i], NULL, deleteAsync, (void*)num);
        usleep(500000);
    }
    for(int i = 0; i < 20; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}
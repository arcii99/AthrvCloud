//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_THREADS 4

pthread_t thread[MAX_THREADS];
pthread_mutex_t mutex_lock = PTHREAD_MUTEX_INITIALIZER; // initialize mutex

char buffer[50];
int buffer_index = 0;

void *copy_string(void *arg) {
    pthread_mutex_lock(&mutex_lock); // lock the mutex
    
    char *str = (char *)arg; // cast argument to string pointer
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        buffer[buffer_index++] = str[i];
        printf("Thread ID: %lu || Char: %c\n", pthread_self(), str[i]);
        sleep(1);
    }
    buffer[buffer_index++] = '\0';
    
    pthread_mutex_unlock(&mutex_lock); // unlock the mutex
    pthread_exit(NULL); // exit the thread
}

int main() {
    char *str[] = {"hello", "world", "how", "are", "you", "doing", "today", "?"};
    
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&thread[i], NULL, (void *)&copy_string, (void *)str[i]); // create threads
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread[i], NULL); // join threads
    }

    printf("New String: %s\n", buffer); // print result

    pthread_mutex_destroy(&mutex_lock); // destroy mutex
    return 0;
}